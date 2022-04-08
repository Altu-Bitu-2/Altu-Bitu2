#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input; // 거점지를 방문한 횟수 1<=n<=5,000
    priority_queue<int> pq; //최대 힙

    //입력
    cin >> n;
    while (n--) { //거점지 방문횟수만큼 반복
        cin >> a; //0이면 아이들을 만나고 그 외에는 선물의 개수
        if (!a) { //아이들을 만난 경우
            if (pq.empty()) { //줄 선물이 없으면 -1 출력
                cout << "-1\n";
            } else { //줄 선물이 있으면 가장 가치가 큰 것(최대힙)을 출력 후 삭제
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else { //선물을 충전하는 경우
            while (a--) {
                cin >> input; //선물의 가치 input <=100,000
                pq.push(input); //최대힙에 선물 push
            }
        }
    }
    return 0;
}