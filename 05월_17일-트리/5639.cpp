#include <iostream>

using namespace std;

struct node_info {
    //트리 구조체 선언
    int data;
    node_info *left;
    node_info *right;
};

node_info *makeTree(node_info *node, int data) {
    if (node == NULL) { //이번 노드가 들어가게될 위치
        node = new node_info(); //동적 할당
        node->data = data; //데이터 값 삽입
        node->left = node->right = NULL; //자식 트리를 null로 선언
    } else if (node->data > data) {
        //만약 해당 data가 삽입할 data보다 크다면
        node->left = makeTree(node->left, data); //왼쪽 자식노드에 트리 생성
    } else if (node->data < data) {
        //삽입할 data가 더 크다면
        node->right = makeTree(node->right, data); //오른쪽 자식노드에 트리 생성
    }
    return node; //노드 반환
}

//후위 순회
void postorder(node_info *node) {
    if (node == NULL) {
        //가리키는 노드가 없으면 종료
        return;
    }
    postorder(node->left); //후위 순회이므로 L->
    postorder(node->right); // R ->
    cout << node->data << '\n'; // V
}

/**
 * 맵과 셋 PPT 중 BST 노드 삽입 과정 참고
 *
 * [이진 검색 트리]
 *
 * 1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
 * 2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
 * 3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
 * 4. 완성한 트리를 후위 순회
 */

int main() {
    int input; //트리를 전위 순회한 결과

    //입력 & 연산
    node_info *root = NULL; //왼쪽, 오른쪽 서브트리를 가리키는 포인터
    while (cin >> input) {
        //input을 이용하여 Tree생성
        root = makeTree(root, input);
    }

    //출럭
    postorder(root);
    return 0;
}