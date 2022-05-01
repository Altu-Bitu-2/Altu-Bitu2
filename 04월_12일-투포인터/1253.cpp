#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {
    while (left < right) {
        //left가 right보다 왼쪽에 있을 동안
        if (left == idx) {
            //idx번째의 수와 left의 수가 같다면 left를 증가시킴
            left++;
            continue;
        }
        if (right == idx) {
            //idx번째의 수와 right의 수가 같다면 right 감소
            right--;
            continue;
        }

        if (num[left] + num[right] == num[idx]) {
            //left의 수와 right수를 합해서 idx번째 수와 같다면 좋은 수
            return true;
        }
        if (num[left] + num[right] > num[idx]) {
            //수를 합해서 idx번째 수보다 크다면 right 감소
            right--;
        } else {
            //작다면 left 증가
            left++;
        }
    }
    //해당하는 조건이 없다면 좋은 수가 아님
    return false;
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0; //수의 개수 1<=n<=2,000, 좋은 수의 개수 ans

    //입력
    cin >> n;
    vector<int> num(n, 0); //n개의 수를 저장할 벡터
    for (int i = 0; i < n; i++) {
        //수 입력
        cin >> num[i];
    }

    //연산
    sort(num.begin(), num.end()); //오름차순 정렬
    for (int i = 0; i < n; i++) {
        //벡터를 방문하면서 좋은 수인지 확인
        if (isGood(num, 0, n - 1, i)) {
            ans++;
        }
    }

    //출력
    cout << ans;
    return 0;
}