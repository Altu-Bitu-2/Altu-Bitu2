#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll; //long long 타입을 ll로 축약
const ll INF = 3 * 1e9 + 1; //최댓값

ll min_diff = INF; //최소값 초기화

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll> &arr, ll fixed, int left, int right) {
    pair<ll, ll> ans; //두 용액을 섞어 0에 가까운 값 찾기
    ans = make_pair(INF, INF); //최댓값으로 pair 생성

    while (left < right) { //left가 right의 왼쪽에 있을 동안 반복
        ll mix = fixed + arr[left] + arr[right]; //고정된 용액과 왼쪽, 오른쪽 용액 섞음
        if (mix == 0) { //0이라면 바로 리턴
            return make_pair(arr[left], arr[right]);
        }
        if (abs(mix) < min_diff) {
            //섞은 용액의 절댓값이 최솟값보다 작을 경우 최솟값을 섞은 용액으로 바꿈
            min_diff = abs(mix);
            //답을 변경
            ans = make_pair(arr[left], arr[right]);
        }
        if (mix > 0) {
            //섞은 용액이 0보다 크면 right값을 줄이고
            right--;
        } else {
            //섞은 용액이 0보다 작으면 left값을 키운다
            left++;
        }
    }
    return ans; //답 리턴
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * [세 용액]
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n; //전체 용액의 수 3<=n<=5,000

    //입력
    cin >> n;
    vector<ll> arr(n, 0); //용액의 특성(산성/알카리성)값을 저장한 벡터
    for (int i = 0; i < n; i++) {
        //용액의 특성 입력. -1e9 <= arr <= 1e9이므로 ll을 사용
        cin >> arr[i];
    }

    //연산
    sort(arr.begin(), arr.end()); //오름차순으로 정렬
    tuple<ll, ll, ll> ans; //세 개의 용액을 섞어 0에 가장 가까운 용액
    for (int i = 0; i < n - 2; i++) {
        //용액의 특성값을 저장한 벡터의 0부터 n-3까지 (3개의 용액)
        //현재의 용액은 고정하고 left = i+1, right = n-1 투포인터로 탐색
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second); //섞어서 0에 가장 가까운 용액 tuple 생성
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0;
}