#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>> &graph) {
    //깊이 탐색
    int pos = node, len = 0; //지름을 구성하는 노드 중 하나(pos), 그 노드까지의 거리(len)
    for (int i = 0; i < graph[node].size(); i++) {
        //그래프 순회하면서
        int next_node = graph[node][i].first; //다음 노드 = 자식 or 부모 노드
        if (next_node == parent) {
            //다음 노드가 부모 노드라면 pass
            continue;
        }

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.second > len) { //기존 거리보다 길다면 갱신
            len = graph[node][i].second + dfs_search.second; //노드까지의 거리 계산(가중치 합)
            pos = dfs_search.first; //자식 노드의 위치
        }
    }
    return {pos, len}; //위치와 거리 반환
}

/**
 * [트리의 지름]
 *
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */

int main() {
    //노드의 개수n, 간선에 대한 정보(부모 : p, 자식 :c, 가중치 : w)
    int n, p, c, w;

    //입력
    cin >> n;
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //그래프 구조체 선언
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        cin >> p >> c >> w; //간선에 대한 정보 입력
        graph[p].push_back({c, w}); //그래프의 부모에 자식과 가중치를 삽입
        graph[c].push_back({p, w}); //그래프의 자식에 부모와 가중치를 삽입
    }

    //연산
    ci first_node = dfs(1, -1, graph); //트리의 지름(=경로 길이)을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.first, -1, graph); //지름을 구성하는 나머지 다른 노드 찾기

    //출력
    cout << second_node.second; //거리 출력
    return 0;
}