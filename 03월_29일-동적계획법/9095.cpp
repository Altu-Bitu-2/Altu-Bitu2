#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10; //정수 최댓값

//bottom-up 방식 dp 배열 채우기
vector<int> numberOfAllCases() {
    vector<int> dp(MAX + 1, 0); // 동적 계획법을 위한 dp 벡터

    dp[0] = dp[1] = 1; //0과 1을 1,2,3의 합으로 나타내는 방법은 1가지
    dp[2] = 2; //2를 1,2,3의 합으로 나타내는 방법(1+1, 2)은 2가지
    for (int i = 3; i <= MAX; i++) {
        //3부터 -1, -2, -3한 인덱스에 +1, +2, +3했다고 생각하기
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp; //방법의 수 리턴
}

/**
 * [bottom-up 접근]
 * 각 수를 인덱스로 써서 정수 n까지 1, 2, 3의 합으로 나타내는 방법의 수를 저장하자!
 *
 * 우선 3까지 1, 2, 3의 합으로 나타내는 방법의 수 초기화 함
 * 해당 인덱스에서 -1, -2, -3 한 인덱스에 +1, +2, +3을 해줬다고 생각하면 됨
 *
 * -> dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3] (n >= 3)
 *
 * 해당 풀이는 인덱스 관리를 편하게 하기 위해 0을 더미 인덱스로 줘서 인덱스 3부터 연산
 * 테스트케이스로 입력이 들어오고, 입력 범위가 11로 작기 때문에 미리 dp 배열 채우고 시작하는 것이 더 효율적
 */

int main() {
    int t, n; // 테스트 케이스 t, 정수 n <11

    //미리 dp 채우기
    vector<int> dp = numberOfAllCases();

    //입력
    cin >> t;
    while (t--) {
        cin >> n;

        //출력
        cout << dp[n] << '\n';
    }
    return 0;
}