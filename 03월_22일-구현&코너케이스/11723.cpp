#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;

// 집합 : 단순 구현 문제.
// 배열을 사용하여 구현(1<=n<=20)
// 1. 집합에는 1~20의 숫자만 입력 or 제거 (true of flase)
// 2. 크기 21의 bool 배열을 선언
// 3. 입력은 true, 제거는 false

int main() {
    //입력속도 빠르게
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    int m, num;
    string cmd; // 커맨드 입력
    vector<bool> s(SIZE, false); //집합 원소 배열 표현

    cin >> m;
    while (m--) {
        cin >> cmd;
        //all : s를 [1,2, ... ,20]으로 바꿈
        if (cmd == "all") {
            s.assign(SIZE, true);
            continue;
        }
        //empty : 공집합으로 변경
        if (cmd == "empty") {
            s.assign(SIZE, false);
            continue;
        }

        //add : 해당 원소를 넣음(이미 있는 경우는 무시)
        cin >> num;
        if (cmd == "add") {
            s[num] = true;
            continue;
        }

        //remove : 해당 원소 제거 (이미 없으면 무시)
        if (cmd == "remove") {
            s[num] = false;
            continue;
        }

        //check : 집합에 해당 원소 있으면 1, 없으면 0 출력
        if (cmd == "check") {
            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }

        //toggle : x가 있으면 x를 제거하고 없으면 추가
        if (cmd == "toggle") {
            s[num] = !s[num];
            continue;
        }
    }
    return 0;
}