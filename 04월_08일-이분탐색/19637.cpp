#include <iostream>
#include <map>

using namespace std;

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {
    //입력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power; //칭호의 개수 1<=n<=1e5, 캐릭터 개수 1<=m<=1e5, 전투력 power
    string name; //칭호명

    //입력
    cin >> n >> m;
    while (n--) {
        //칭호의 개수만큼 반복
        cin >> name >> power; //칭호명과 해당 칭호의 전투력 상한값 입력
        if (title[power].empty()) {
            //만약 칭호가 비어있다면 넣어줌
            title[power] = name;
        }
    }

    //출력
    while (m--) {
        // 칭호의 개수만큼 반복
        cin >> power; //전투력 입력
        cout << title.lower_bound(power)->second << '\n'; //해당 칭호의 전투력을 계산하여 Weak, normal, strong 출력
    }
}