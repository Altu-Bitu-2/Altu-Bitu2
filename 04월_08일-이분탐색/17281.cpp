#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings; //이닝에서 얻는 결과를 저장하는 배열
vector<int> order(10, 0); //타자의 타순
vector<bool> check(10, false); //현재 선수의 순서가 정해졌는지 체크하는 배열
int n, ans; //이닝 수(2<=n<=50), 아인타팀이 얻을 수 있는 최대점수 ans

//각 루타마다 얻는 점수
int hitScore(int hit, vector<bool> &baseman) {
    int score = 0; //루타마다 얻는 점수
    for (int i = 3; i >= 0; i--) {
        //3루타에서 홈까지 반복
        if (!baseman[i]) {
            //i 루수에 선수가 없으면 다음 루타로 넘어감
            continue;
        }
        if (i + hit >= 4) {
            //루수와 타수의 합이 4이상이면 1점 얻음
            score ++;
        } else {
            //그렇지 않다면 i 루수에 선수있음
            baseman[i + hit] = true;
        }
        baseman[i] = false; // 다 돌았는데도 조건에 걸리지 않으면 i루수에 선수 없음
    }
    if (hit == 4) {
        //홈런을 했다면 1점 증가
        score++;
    } else {
        baseman[hit] = true; //새로운 선수들 홈에 도착
    }
    return score; //점수 리턴
}

//현재 배치의 점수
int calcScore() {
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while (out < 3) {
            //삼진아웃이 되지 않을 때까지
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if (idx == 10) {
                //order가 10번이면 1번으로 초기화
                idx = 1;
            }
            if (state == 0) {
                // state : 0번은 아웃
                out++;
            } else {
                //아웃이 아니면 점수 증가
                score += hitScore(state, baseman);
            }
        }
    }
    return score; //점수 리턴
}

//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        array(cnt + 1); //다음 타자
        return;
    }
    if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score); //최대 점수
        return;
    }
    for (int i = 2; i <= 9; i++) {
        //2번타자부터 9번타자까지
        if (!check[i]) {
            //해당 선수의 순서가 정해지지 않았다면
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt + 1); //다음 타자
            check[i] = false; //다시 초기화
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    //입력
    cin >> n; //이닝 수
    innings.assign(n, vector<int>(10, 0)); //각 선수가 각 이닝에서 얻는 결과 배열
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 10; j++) {
            // 2차원 배열로 입력
            cin >> innings[i][j];
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수
    check[1] = true; //1번 선수는 순서 정해짐
    array(1);

    //출력
    cout << ans;
    return 0;
}