#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
 * 상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
 */

int main() {
    //입력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input; //열과 행의 수 1<=n<=1500, 입력할 수 -1e9 <= input <= 1e9
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙, 정렬이랑 반대

    cin >> n;
    int size = n * n; // n*n 표의 크기
    while (size--) { //size 수만큼 반복
        //입력
        cin >> input; //정수 입력

        //연산
        pq.push(input); //우선순위 큐에 정수 삽입
        if (pq.size() > n) { //최소 힙의 크기가 n 이상이라면 가장 작은 값 삭제
            pq.pop(); //최소 힙이므로 가장 작은 값은 top에 있음
        }
    }

    //출력
    cout << pq.top(); //n번째 큰 수를 출력
    return 0;
}