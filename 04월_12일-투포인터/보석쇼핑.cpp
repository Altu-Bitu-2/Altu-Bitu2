#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//같은 위치에서 시작하여 같은 방향으로 이동하는 투 포인터
//모든 보석 종류를 포함하는 가장 짧은 구간 리턴
vector<int> gemListTwoPointer(int left, int right, int gem_size, vector<string> &gems, map<string, int> &m) {
    int size = gems.size(); //전체 보석 개수
    vector<int> ans = {1, size}; //구간을 리턴할 답 초기화

    //초기 구간 설정
    m[gems[left]]++;
    int cnt = 1; //보석 종류 개수
    while (left <= right && right < size) {
        //left가 right의 왼쪽에 있고, right는 size보다 작을 동안
        if (cnt == gem_size) { //모든 종류의 보석이 있음 -> 구간 짧게
            if (right - left < ans[1] - ans[0]) {
                //현재 벡터의 size가 ans의 size보다 짧으면
                //ans의 구간을 짧게
                ans = {left + 1, right + 1};
            }
            if (--m[gems[left]] == 0) { //더이상 이 보석이 없다면 제거
                cnt--;
            }
            left++; //left 증가
        } else if (cnt < gem_size) { //모든 종류의 보석이 있는게 아니라면
            right++; //구간을 길게하기 위해 right 이동
            if (right == size) { //런타임 에러 방지
                break;
            }
            if (m[gems[right]]++ == 0) { //보석 종류 처음 등장이라면
                //보석 종류 개수를 증가
                cnt++;
            }
        }
    }
    return ans;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    map<string, int> m; //보석의 종류를 구할 중복 허용 안되는 맵 세팅
    for (int i = 0; i < gems.size(); i++) {
        //보석의 종류와 개수를 초기화
        m[gems[i]] = 0;
    }
    int gem_size = m.size(); //보석의 종류의 수

    //투 포인터를 사용해 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간 구함
    answer = gemListTwoPointer(0, 0, gem_size, gems, m);
    return answer;
}

/**
 * [보석 쇼핑]
 * : 진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간을 찾아서 구매
 *
 * 1. map을 활용해 보석의 종류 구함 (중복 x)
 * 2. 같은 위치에서 시작해서 같은 방향으로 이동하면서 모든 종류 포함하는 구간의 최소값 찾아감 (투 포인터)
 *    - 이때, 구간 안에 보석 종류의 존재 여부를 map을 통해서 관리
 */

int main() {
    //입력
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};

    //연산
    vector<int> ans = solution(gems);

    //출력
    cout << ans[0] << ' ' << ans[1];
}