#include <iostream>
#include <vector>

using namespace std;

//새로운 점수의 랭킹을 리턴할 함수
int findRanking(int n, int new_score, int p, vector<int> &ranking) {
    int idx = 1; //현재 인덱스
    int ans = 1; //새로운 점수의 랭킹
    //새로운 점수를 어느 위치에 넣을지 탐색
    while (idx <= n) {
        //인덱스가 n보다 작거나 같을 때까지
        if (new_score > ranking[idx]) {
            //만약 새로운 점수가 현재 랭킹 점수보다 높다면 종료
            break;
        }
        if (new_score < ranking[idx]) {
            //만약 새로운 점수가 현재 랭킹 점수보다 낮다면
            ans = idx + 1; //새로운 점수의 랭킹은 인덱스 +1
        }
        idx++; // 인덱스 증가
    }
    if (idx == p + 1) { //랭킹 리스트에 들어가지 못하는 경우
        return -1;
    }
    return ans; //랭킹 리턴
}

/**
 * [등수 구하기]
 *
 * 1. n = 0일 때, 고려
 * 2. 등수는 p보다 작지만, 점수가 더 좋을 때만 랭킹이 갱신되므로 랭킹 리스트에 들어가지 못하는 경우 고려 (동점)
 *
 * 현재 랭킹에 올라간 n까지 등수와 새로운 점수를 비교하며 새로운 점수 몇 등인지 계산
 * 새로운 점수가 현재 탐색 등수의 점수보다 작다면 -> 현재 탐색 등수 + 1
 * 동점일 경우 -> 그 전 등수 그대로 사용 -> 아무 처리도 하지 않음!
 */

int main() {
    //랭킹 리스트의 점수 n개
    //태수의 새로운 점수 0 <= new_score <=2,000,000,000
    //리스트에 올라갈 수 있는 점수의 개수 10<=p<=50
    int n, new_score, p;

    //입력
    cin >> n >> new_score >> p;
    vector<int> ranking(p + 1, 0); //랭킹 리스트
    for (int i = 1; i <= n; i++) {
        //랭킹 리스트에 올라갈 점수 입력
        cin >> ranking[i];
    }

    //연산 & 출력
    cout << findRanking(n, new_score, p, ranking);
    return 0;
}