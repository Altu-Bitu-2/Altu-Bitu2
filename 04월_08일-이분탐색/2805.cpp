#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll; //long long type 축약

//집에 가져갈 나무의 개수
ll cntTree(int height, vector<int> &tree) {
    ll sum = 0; 
    for (int i = 0; i < tree.size(); i++) {
        //나무의 개수만큼 반복
        if (height >= tree[i]) {
            //만약 나무가 해당 높이보다 작거나 같으면 개수 리턴
            return sum;
        }
        sum += (tree[i] - height); // 절단하고 남은 나무 높이 합
    }
    return sum;
}

//적어도 m미터의 나무를 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값
int upperSearch(int left, int right, int target, vector<int> &tree) {
    while (left <= right) {
        //left는 항상 right보다 왼쪽에 있어야 함
        int mid = (left + right) / 2; //중간값 설정
        ll tree_cnt = cntTree(mid, tree); //절단된 나무의 개수

        if (tree_cnt >= target) {
            //개수가 목표보다 크다면 left를 오른쪽으로 옮김
            left = mid + 1;
        } else {
            //개수가 목표보다 작으면 right를 왼쪽으로 옮김
            right = mid - 1;
        }
    }
    return left - 1; //최댓값 리턴
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m; // 나무의 수 (1<=n<=1,000,000) 나무의 길이 (1<=m<=2,000,000,000)

    //입력
    cin >> n >> m;
    vector<int> tree(n, 0); //나무 배열
    for (int i = 0; i < n; i++) {
        //나무의 수만큼 반복하여 나무의 높이 입력
        cin >> tree[i];
    }

    //내림차순으로 나무 높이 정렬
    sort(tree.begin(), tree.end(), greater<>());

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);
    return 0;
}