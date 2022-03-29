#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//숫자 할리갈리 게임
// 더미의 가장 위에 있는 숫자의 합이 5가 되면 종을 치고 상대방의 카드를 뒤집어 자신의 덱 아래로 다 가져옴, 단 플레이어의 앞에 카드가 1장 이상 있어야함

//그라운드에 있는 카드를 덱으로 옮기는 함수
void moveCard(deque<int> &deck, deque<int> &ground){
    while (!ground.empty()){
        //그라운드가 비어있지 않다면 그라운드의 카드를 뒤부터 덱의 뒤에 push
        deck.push_back(ground.back());
        ground.pop_back();
    }
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>> &deck, vector<deque<int>> &ground) {
    bool turn = false; //도도부터 시작

    while(m--){
        //이번 턴의 사람이 카드 뒤집어서 그라운드에 놓기
        int card= deck[turn].front(); //deck[0]의 앞에 있는 카드를 뽑음
        ground[turn].push_front(card);
        deck[turn].pop_front();

        //갖고있는 카드가 없으면 끝
        if(deck[turn].empty()){
            break;
        }

        //이번에 종을 칠 사람
        int bell = -1;
        if (card == 5){
            //카드의 합이 5이면 종치기
            bell = 0;
        }
        else if (!ground[0].empty() && ! ground[1].empty() && (card + ground[!turn].front() == 5)){
            //만약 그라운드가 비어있지 않고 상대방의 카드와 내 카드의 합이 5이면 종 침
            bell = 1;
        }

        if(bell != -1){
            //종을 치면, 상대방의 그라운드 카드를 뒤집어서 카드 더미 밑에 넣는다.
            moveCard(deck[bell], ground[!bell]);
            moveCard(deck[bell], ground[bell]);
        }

        turn = !turn; //차례 바꾸기
    }

    return make_pair(deck[0].size(), deck[1].size());
}

int main() {
    int n, m; //카드 개수 1<=n<=30,000, //게임 진행 횟수 1<=m<=2,500,000

    int num1, num2; //넣을 카드
    vector<deque<int>> deck(2), ground(2);
    cin >> n >> m;

    while(n--){
        cin >> num1 >> num2;
        deck[0].push_front(num1);
        deck[1].push_front(num2);
    }

    pair<int, int> result = playGame(m, deck, ground);

    if(result.first == result.second){
        //무승부면
        cout << "dosu\n";
    }

    else if (result.first > result.second){
        //도도가 이겼으면
        cout << "do\n";
    }

    else if (result.first < result.second){
        //수연이가 이겼으면
        cout << "su\n";
    }
}