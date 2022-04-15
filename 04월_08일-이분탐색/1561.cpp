#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll; //입력 범위가 2e9이므로 long long 타입 사용

//마지막 아이가 타는 운행시간
ll finalChildren(ll t, vector<int> &rides) {
    ll child = 0;
    for (int i = 1; i < rides.size(); i++) {
        //1부터 놀이기구 수만큼 반복
        child += (t / rides[i] + 1); //운행시간을 더함
    }
    return child;
}

// 놀이기구를 타는 첫 시간을 구하는 함수
ll lowerSearch(ll left, ll right, ll target, vector<int> &rides) {
    while (left <= right) {
        //left는 항상 right보다 왼쪽에 있어야함
        ll mid = (left + right) / 2; //중간값
        ll child = finalChildren(mid, rides); //마지막 아이가 타는 운행시간 구함

        if (child >= target) { //줄의 마지막 아이보다 더 뒤에 있는 아이라면
            right = mid - 1; //right를 왼쪽으로 옮김
        } else {
            //줄의 마지막 아이보다 앞에 있다면 left를 오른쪽으로 옮김
            left = mid + 1;
        }
    }
    return left; //
}
//마지막 아이가 타게 되는 놀이기구의 번호를 알아내는 함수
int findRides(int n, int m, vector<int> &rides) {
    ll t = lowerSearch(0, (ll) rides[1] * n, n, rides); //n번째 아이가 놀이기구를 타는 첫 시간을 구함
    ll child = finalChildren(t, rides); //n번째 아이가 타는 운행 시간
    for (int i = m; i >= 1; i--) {
        //놀이기구 수만큼 반복
        if (t % rides[i] == 0) { //아이가 탐
            if (child-- == n) {
                //만약 운행시간이 n이라면 그 놀이기구 리턴, 그리고 운행 시간 감소
                return i;
            }
        }
    }
}

/**
 * [놀이 공원]
 *
 * n번째 아이가 놀이기구를 타는 시간을 구한 후, 해당 시간에 놀이기구를 타는 아이들을 모두 검사하며 n번째 아이가 타는 놀이기구의 번호를 구한다!
 *
 * 1. n번째 아이가 놀이기구를 타는 시간이 언제인지 parametric search 통해 구함
 *    - 이때, 각 시간 별 놀이기구 타는 아이의 마지막 번호 구하는 공식은 다음과 같음
 *      f(t) = (모든 i(놀이 기구)에 대해서) t/num[i] + n(시간 0일때 놀이기구 타는 아이 수)
 *
 *    - left: 놀이기구 타는 시간의 최소 = 0
 *    - right: 놀이기구 타는 시간의 최대 = 1번 놀이기구 운행 시간 x n (타이트하게 잡으면 최소 운행 시간 x n 이지만 편의상 이렇게 설정)
 *
 *    - n번째 아이가 놀이기구를 타는 첫 시간을 구해야 하므로 lower bound
 *
 * 2. n번째 아이가 놀이기구를 타는 시간을 구했다면, 그 시간에 마지막으로 놀이기구를 타는 아이부터 시작해서
 *    놀이기구를 m부터 탐색하면서 n번째 아이가 몇 번 놀이기구 타는지 구하면 됨!
 */

int main() {
    int n, m; //n명의 아이(1<=n<=2e9), 놀이기구(1<=m<=10,000)

    //입력
    cin >> n >> m;
    vector<int> rides(m + 1, 0); //놀이기구의 운행 시간을 저장한 배열
    for (int i = 1; i <= m; i++) {
        //1번부터 놀이기구 수만큼 반복하여 운행 시간을 입력
        cin >> rides[i];
    }

    if (n <= m) { //아이의 수가 놀이기구 수보다 적다면
        cout << n; //n번째 아이가 n번째 놀이기구를 탐
        return 0;
    }

    //연산 & 출력
    cout << findRides(n, m, rides);
    return 0;
}