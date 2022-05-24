#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {
    if (node == erase_node) {
        //루트노드를 삭제한다면 남은 노드가 없으므로
        return 0; //0을 반환
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        //트리가 비어있거나 트리의 크기가 1이고 루트를 삭제한다면
        return 1; //1을 반환
    }
    int cnt = 0; //리프노드의 개수
    for (int i = 0; i < tree[node].size(); i++) {
        //트리를 순회하면서
        cnt += eraseLeafCnt(tree[node][i], erase_node); //리프노드의 개수 더함
    }
    return cnt; //리프노드의 개수 반환
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    //트리 노드 개수 n, 각 노드의 부모 par, 루트 노드 root, 삭제할 노드 erase_node
    int n, par, root, erase_node;

    //입력
    cin >> n; //노드 개수 입력
    tree.assign(n, vector<int>(0)); //트리 초기화
    for (int i = 0; i < n; i++) {
        cin >> par; //부모 노드 입력
        if (par == -1) {
            //만약 부모가 -1이면 == root 노드라면
            root = i;
            continue; //다음으로 pass
        }
        tree[par].push_back(i); //부모노드에 번호 삽입
    }
    cin >> erase_node; //삭제할 노드 번호 입력

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node);
    return 0;
}