#include <iostream>
#include <queue>

using namespace std;
typedef long long ll; //long long타입을 쉽게 쓰도록 선언

//파일을 하나로 합칠때 필요한 최소비용을 계산하는 함수
ll getCost(priority_queue<ll, vector<ll>, greater<>> &pq) {
    ll ans = 0; //최소비용

    while (pq.size() > 1) { //우선순위 큐의 크기가 1보다 클때까지 반복
        ll card1 = pq.top(); //최소비용의 파일을 꺼냄
        pq.pop();
        ll card2 = pq.top(); //그다음 최소비용의 파일을 꺼냄
        pq.pop();
        ans += card1 + card2; //비용 계산
        pq.push(card1 + card2); //파일 합치기
    }
    return ans;
}

/**
 * [파일 합치기 3]
 *
 * - 파일을 전부 합치기 위해서는 어차피 하나로 만들어야 한다!
 * - 이 때, 여러번 더해지는 값은 작을 수록 좋다
 * - 따라서, 현재 가장 작은 파일 2개를 합쳐야 비용을 최소화 할 수 있다.
 * -> 최소 힙으로 구현
 *
 * !주의! 파일의 개수는 최대 1,000,000 이고 각 크기의 최대는 10,000이므로
 *       정답의 최댓값이 10^10으로 int 범위를 넘기 때문에 long long 써야 함
 */

int main() {
    int t, k, file; //테스트 데이터 t, 소설을 구성하는 페이지 수 3<=k<=1,000,000, 1장부터 k장까지 수록한 파일의 크기 file <=10,000

    //입력
    cin >> t;
    while (t--) { //테스트케이스 수만큼 반복
        priority_queue<ll, vector<ll>, greater<>> pq; //최소힙 선언 (최소 비용이 top에 있음)

        //입력
        cin >> k;
        for (int i = 0; i < k; i++) { // 페이지 수만큼 반복
            cin >> file; //파일의 크기 입력 후 push
            pq.push(file);
        }

        //연산 & 출력
        cout << getCost(pq) << '\n';
    }
    return 0;
}