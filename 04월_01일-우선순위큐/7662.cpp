#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci; //정수형을 쌍으로 받는 데이터타입 선언

vector<bool> is_valid; //각 데이터가 유효한지 체크하는 배열

//최대 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMax(priority_queue<ci> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) {
        //힙이 비어있지 않고 데이터의 인덱스가 유효하지 않으면 제거
        heap.pop();
    }
}

//최소 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMin(priority_queue<ci, vector<ci>, greater<>> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) {
        //힙이 비어있지 않고 데이터의 인덱스가 유효하지 않으면 제거
        heap.pop();
    }
}

/**
 * 우선순위 큐 풀이
 * 최대 힙과 최소 힙을 동시에 관리하면서 각각의 힙에서 삭제된 데이터를 다른 힙에 반영하는 방법
 * -> 각 데이터의 유효성을 체크하는 배열을 만들기
 * 
 * 이중 우선순위 큐 : 전형적인 우선순위 큐처럼 데이터를 삽입, 삭제할 수 있음. 차이점은 데이터를 삭제할 때 연산 명령에 따라 우선순위가 가장 높은 데이터 or 가장 낮은 데이터 중 하나를 삭제함
 * 데이터를 삭제하는 연산 두 가지로 나뉨
 */
int main() {
    int t, k, n; //입력 데이터의 수 t, q에 적용할 연산의 개수를 나타내는 k<=1,000,000, 연산을 처리할 정수 n
    char cmd; //연산 명령어 (삽입 I 삭제 D, -1은 최솟값, 1은 최댓값)

    cin >> t; //입력 데이터를 받음
    while (t--) {
        priority_queue<ci> max_heap; //최대 힙
        priority_queue<ci, vector<ci>, greater<>> min_heap; //최소 힙
        cin >> k; //연산의 개수를 입력 받음
        int idx = 0; //I 연산으로 입력된 숫자의 인덱스
        while (k--) {
            //입력 : 연산과 정수
            cin >> cmd >> n;

            //연산
            switch (cmd) {
                case 'I': //두가지 힙 모두에 값을 넣은 뒤, is_valid 벡터에도 추가
                    max_heap.push(ci(n, idx)); //정수와 인덱스 입력
                    min_heap.push(ci(n, idx)); //정수와 인덱스 입력
                    is_valid.push_back(true); //해당 데이터가 유효함
                    idx++; //인덱스 +1
                    break;
                case 'D': //n에 따라 최대 힙 또는 최소 힙에서 데이터 삭제
                    if (n == 1) { //최댓값을 삭제하는 연산
                        deleteMax(max_heap); //D연산 전처리
                        if (!max_heap.empty()) { //D연산
                            is_valid[max_heap.top().second] = false; //해당 인덱스의 유효성을 제거
                            max_heap.pop(); //데이터 삭제
                        }
                    }
                    if (n == -1) { //최솟값을 삭제하는 연산
                        deleteMin(min_heap); //D연산 전처리
                        if (!min_heap.empty()) { //D연산
                            is_valid[min_heap.top().second] = false; //해당 인덱스의 유효성 제거
                            min_heap.pop(); //데이터 삭제
                        }
                    }
                    break;
            }
        }
        //마지막으로 각 힙의 top이 valid 하도록 처리
        deleteMax(max_heap);
        deleteMin(min_heap);

        //출력
        if (max_heap.empty()) {
            cout << "EMPTY\n"; //비어 있으면 비었음을 출력
        }
        else { //비어있지 않으면 각 힙의 top과 인덱스를 출력
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';
        }
        is_valid.clear(); //새로운 테스트 케이스 전 is_valid 벡터 초기화
    }
}