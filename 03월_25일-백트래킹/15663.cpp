#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 8; //배열 크기

int n, m; //자연수 1 <= m <= n <= 8, 길이가 m인 수열 구하기
vector<int> num(SIZE); //수열
vector<int> ans(SIZE); //답 수열
vector<bool> check(SIZE); // 같은 위치의 수인지 중복제거하는 배열

void backtracking(int cnt) {
    if (cnt == m) { //길이 m 이라면 (기저조건)
        for (int i = 0; i < m; i++) {
            //길이 m까지 답을 출력
            cout << ans[i] << ' ';
        }
        cout << '\n'; // 띄워쓰고 리턴
        return;
    }
    int prev = 0; //이전에 선택한 값
    for (int i = 0; i < n; i++) {
        //n개의 수 반복
        if (!check[i] && prev != num[i]) { //수 위치 중복 체크 && 이전에 탐색한 값이 아니라면
            prev = num[i]; //이전 값을 현재 i의 수열 원소 대입
            ans[cnt] = num[i]; //답으로 정렬한 배열에 현재 값을 넣기
            check[i] = true; //i숫자 넣었음을 체크 (중복 제거)
            backtracking(cnt + 1); //다음 차례로 재귀
            check[i] = false; //중복 제거한 배열을 다시 false로 원상복귀
        }
    }
}

/**
 * 1. 우선 수열을 사전 순으로 증가하는 순서로 출력해야 하므로 주어진 수열을 오름차순 정렬
 * 2. 이 상태에서 우선, 같은 위치의 수를 또 선택하지 않도록 중복제거 (check 배열 사용)를 해줌
 * 3. 그 후, 중복되는 "수열"을 거르는 방법은 이전에 선택한 값을 변수에 저장해서, 수열을 만들다 다시 루트 노드로 돌아왔을 때
 *    이전에 선택한 값과 같은 값이면 넘어가면 됨! -> 어차피 같은 수이므로 같은 과정 반복해서 똑같은 수열이 나올 것
 */

int main() {
    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        //자연수
        cin >> num[i];
    }

    //연산
    sort(num.begin(), num.begin() + n); //사전 순으로 증가하는 오름차순 정렬, n개만

    //백트래킹 & 출력
    backtracking(0);
    return 0;
}