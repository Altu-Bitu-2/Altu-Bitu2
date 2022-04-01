#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9; //최댓값 10억
const int SIZE = 11;

int n; //수의 개수 2<=n<=11
vector<int> num(SIZE + 1); //수열
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX; //최솟값과 최댓값 정의

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum); //합의 최댓값
        min_value = min(min_value, sum); //합의 최솟값
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) {
            //만약 연산자가 존재하면
            expression[i]--; //개수 -1
            int new_sum = 0; //값을 저장할 임시 변수
            switch (i) { //연산자 종류에 따라
                case 0: // +
                    new_sum = sum + num[cnt + 1];
                    break;
                case 1: // -
                    new_sum = sum - num[cnt + 1];
                    break;
                case 2: // *
                    new_sum = sum * num[cnt + 1];
                    break;
                case 3: // /
                    new_sum = sum / num[cnt + 1];
                    break;
            }
            backtracking(cnt + 1, new_sum); //연산수를 +1하며 합한 결과로 다시 재귀
            expression[i]++; //개수 원래대로 돌리기
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        //수열 입력
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        //합이 n-1인 4개의 정수, 순서대로 덧셈, 뺄셈, 곱셈, 나눗셈의 개수
        cin >> expression[i];
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}