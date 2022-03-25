#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

struct baseball {
    string num; //서로 다른 세 자리 수
    int strike, ball; //스트라이크 개수, 볼 개수
};

ci cntStrikeBall(string &s1, string &s2){
    //스트라이크인지 볼인지 개수 체크
    int strike_cnt = 0; //s1과 s2사이 스트라이크
    int ball_cnt = 0; //s1과 s2사이 볼

    for(int i = 0; i<3; i++){
        if(s1[i] == s2[i]){
            //위치와 수 일치 -> 스트라이크
            strike_cnt++;
        }
        else if(s1.find(s2[i]) != s1.npos){
            //위치 다른데 같은 수 존재 -> 볼
            ball_cnt++;
        }
    }

    return ci(strike_cnt, ball_cnt);
}

int game(int n, vector<baseball> &question){
    int ans = 0; //정답 개수

    //서로 다른 세 자리수 123~987가 가능
    //n의 범위는 100까지이므로 123부터 하나씩 증가시키며 정답이 되는지 검사
    for(int i=123; i<=987; i++){
        bool check = true;
        string s1 = to_string(i); //정답인지 확인할 숫자

        if(s1[0] == '0' || s1[1]=='0' || s1[2] == '0'){
            //0이 하나라도 있다면
            continue;
        } 
        if(s1[0] == s1[1] || s1[0]==s1[2] || s1[1] == s1[2]){
            //서로 같은 수가 하나라도 있다면
            continue;
        }
        for(int j=0; j<n; j++) {
            string s2 = question[j].num; //질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2); //s1과 s2사이 스트라이크와 볼 개수
            if(cnt.first != question[j].strike || cnt.second != question[j].ball){
                //직접 체크한 스트라이크와 볼 개수가 다르면
                check = false;
                break;
            }
        }

        //개수가 맞다면 정답 +1
        if(check){
            ans++;
        }

        
        
    }
    return ans;
}
int main (){
    //입력
    int n; //질문 n의 범위 최대 100
    cin >> n;

    //질문 벡터
    vector<baseball> question(n);
    for(int i=0; i<n; i++){
        cin >> question[i].num >> question[i].strike >> question[i].ball;
    }

    //연산 및 출력
    cout << game(n, question);

    return 0;

}