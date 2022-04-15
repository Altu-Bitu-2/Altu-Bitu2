#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//추를 사용하여 측정할 수 없는 양의 정수 무게 중 최솟값을 구하는 함수
int findUnmeasurable(vector<int> &weight) {
    int sum = 0; //추의 합

    for (int i = 0; i < weight.size(); i++) {
        //작은 값부터 모든 저울을 살펴서
        if (sum + 1 < weight[i]) {
            //추의 합 + 1보다 현재 무게가 작을경우 즉, 측정이 불가능하므로
            return sum + 1; //추의 합 + 1을 리턴
        }
        sum += weight[i]; //새로운 무게로 갱신
    }
    return sum + 1; //비어있는 값이 없으면 추의 합+1을 리턴
}

/**
 * [저울]
 *
 * 작은 값부터 측정 가능한지 파악해야 하므로, 오름차순으로 정렬한다.
 * 현재 0부터 scope까지 모든 무게를 빠짐없이 측정가능하다고 했을 때, 새로운 무게는 scope + 1보다 작거나 같아야 한다.
 * ex) 현재 1~5까지 측정 가능한데, 다음 값이 7인 경우 -> 6은 측정 불가
 *
 * 만약 이 조건을 만족할 경우, 측정 가능한 범위는 [1, scope + 새로운 무게]로 갱신된다.
 * 모든 저울을 살펴봤는데도 비어있는 값이 없으면, scope + 1 리턴
 */

int main() {
    int n; //무게 양의 정수 1<=n<=1,000

    //입력
    cin >> n;
    vector<int> weight(n, 0); //물건의 무게 배열
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    //정렬 : 오름차순
    sort(weight.begin(), weight.end());

    //연산 & 출력
    cout << findUnmeasurable(weight);
    return 0;
}