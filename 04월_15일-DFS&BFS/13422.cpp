#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {
    //윈도우 초기화
    int money = 0; 
    for (int i = 0; i < m; i++) {
        //집을 방문해 돈을 합침
        money += house[i];
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans; //ans 리턴
    }
    for (int i = m; i < n + m - 1; i++) {
        //슬라이딩 윈도우만큼 반복
        money -= house[i - m]; // 원형 배열이므로 i-m번째 집의 돈을 제외
        money += house[i % n]; //모듈러 연산으로 원형으로 돌아가며 돈 훔침
        if (money < k) {
            //훔칠 돈이 방범 장치가 작동하는 최소 돈의 양보다 작다면
            ans++; //방법의 가짓수 증가
        }
    }
    return ans;
}

/**
 * [도둑]
 *
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 *    => 예를 들어, n = m = 3, k = 4, house = [1, 1, 1] 일 때, 실제 방법의 수는 1번, 2번, 3번 집을 택하는 경우밖에 없지만
 *       예외 처리를 안해줄 경우, 원형으로 돌며 3을 출력하게 됨!
 */

int main() {
    //테스트 케이스 t, 집의 개수 1<=n<=100,000
    //도둑이 돈을 훔칠 연속된 집의 개수 1<=m<=n
    // 자동 방범 장치가 작동하는 최소 돈의 양 1<=k<=1e9
    int t, n, m, k;

    cin >> t;
    while (t--) {
        //입력
        cin >> n >> m >> k;
        vector<int> house(n, 0); //집을 저장할 벡터
        for (int i = 0; i < n; i++) {
            //n개의 집에서 각각 보관중인 돈의 양이 시계방향 순서대로 주어짐
            cin >> house[i];
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';
    }
    return 0;
}