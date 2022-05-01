#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &people, vector<int> &init, int n) {
    vector<int> rest(n + 1, 0); //각 사람이 루머를 믿기 위해 필요한 최소 주변인 수
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q; //방문을 위한 큐

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) {
        //최초 유포자부터 시간 초기화
        ans[init[i]] = 0;
        q.push(init[i]);//큐에 최초 유포자 push
    }

    //루머 믿어야 하는 주변인 수 초기화
    for (int i = 1; i <= n; i++) {
        //최소 절반 이상의 주변인이 믿어야함
        rest[i] = (people[i].size() + 1) / 2;
    }

    while (!q.empty()) {
        int curr = q.front(); //현재 사람
        int t = ans[curr]; //루머 믿은 시간
        q.pop(); //큐에서 제거

        for (int i = 0; i < people[curr].size(); i++) {
            //현재 사람의 주변인의 수만큼 반복
            int next = people[curr][i]; //현재 주변인
            if (ans[next] > -1) { //이미 루머를 믿는다면
                continue; //다음 주변인으로
            }
            rest[next]--; //필요한 최소 주변인의 수 감소
            if (!rest[next]) { //주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = t + 1; //루머가 유포된 시간 분 증가
                q.push(next); //큐에 현재 주변인 push
            }
        }
    }
    return ans; //시간 리턴
}

/**
 * [루머]
 *
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크 배열을 루머를 믿는 시간을 저장하는 배열로 대체함
 *    ans[i] = -1 일 경우, i는 루머를 믿지 않는다
 *    ans[i] = t인 경우, i는 t분 부터 루머를 믿기 시작함
 * 각자가 루머를 믿기 위해 주변인의 절반 이상이 루머를 믿어야 하므로, 각 사람이 루머를 믿기까지 루머를 믿는 주변인 몇명이 남았는지를 리스트에 기록한다.
 * 남은 사람이 0인 순간, 해당 사람은 루머를 믿기 시작
 */

int main() {
    int n, m, input; //사람의 수 n, 최초 유포자의 수 m, n번째 사람의 주변인 input

    //루머 퍼뜨리는 관계 입력
    cin >> n;
    vector<vector<int>> people(n + 1, vector<int>()); //사람의 주변인의 관계를 2차원 벡터에 입력
    for (int i = 1; i <= n; i++) {
        //1번째부터 n번째까지
        while (true) {
            //무한루프
            cin >> input; //주변인 입력
            if (!input) {
                //만약 0이면 입력 종료
                break;
            }
            people[i].push_back(input); //주변인 벡터에 추가
        }
    }

    //최초 유포자 입력
    cin >> m;
    vector<int> init(m, 0); //최초 유포자 벡터
    for (int i = 0; i < m; i++) {
        //m번 반복하면서 유포자 벡터 입력
        cin >> init[i];
    }

    //연산
    vector<int> ans = bfs(people, init, n);

    //출력
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}