#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int blackJack(int n, int m, vector<int> &card){
    int ans = 0; //정답

    vector<bool> is_selected(n, false); //고른 카드가 true

    for(int i=0; i<3; i++){
        is_selected[i] =true; //3장 고른 것으로 초기화
    }

    do{
        int sum = 0; //고른 3장의 카드 합 저장

        //고른 3장의 카드 합 계산
        for(int i=0; i<n; i++){
            if(is_selected[i]){
                sum += card[i];
            }
        }
        //m과 가장 가까운 카드 구하기
        if(sum <= m){
            ans = max(ans, sum);
        }

    } while (prev_permutation(is_selected.begin(), is_selected.end()));
    //모든 조합의 합 구하기

    return ans;
}

//블랙잭
// : 카드 3<=N<=100장에서 중복 가능 3장 뽑기 C(100,3)
// 10<=M<=300,000을 넘지 않는 3장의 최댓값, 각각 100,000을 넘지 않는 수가 써있음
int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> card(n, 0);
    for(int i=0; i<n; i++){
        cin >> card[i];
    }

    //연산
    int ans = blackJack(n, m, card);

    //출력
    cout << ans;

    return 0;
}