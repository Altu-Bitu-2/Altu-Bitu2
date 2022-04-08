#include <iostream>
#include <deque>

using namespace std;

//char를 문자열로 바꾸는 함수
string dqToString(deque<char> &dq) {
    string ans = ""; //답 문자열
    while (!dq.empty()) {
        //덱이 비어있지 않다면
        ans += dq.front(); //차례대로 답에 더함
        dq.pop_front();
    }
    return ans;
}

// 입력한 비밀번호가 무엇인지 알아내는 함수
string findPass(string s) {
    deque<char> dq_left;  //커서 이전 내용을 저장
    deque<char> dq_right; //커서 이후 내용을 저장

    for (int i = 0; i < s.length(); i++) {
        //문자열의 길이만큼 반복
        switch (s[i]) { //문자열의 현재 인덱스를 case문으로 파악
            case '-': //백스페이스 : 현재 커서 앞에 있는 글자를 지운다.
                if (!dq_left.empty()) {
                    //비어있지 않으면 제거
                    dq_left.pop_back();
                }
                break;
            case '<': //커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
                if (!dq_left.empty()) { //dq_left가 비어있지 않으면 연산
                    dq_right.push_front(dq_left.back());
                    dq_left.pop_back(); //dq_left 뒤 원소 제거
                }
                break;
            case '>': //커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
                if (!dq_right.empty()) { // dq_right가 비어있지 않으면 연산
                    dq_left.push_back(dq_right.front());
                    dq_right.pop_front(); //dq_right 뒤 원소 제거
                }
                break;
            default: //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
                dq_left.push_back(s[i]);
                break;
        }
    }

    string pass = dqToString(dq_left); //패스워드
    pass += dqToString(dq_right); //dq_right에 있는 남은 문자 더함
    return pass;
}

/**
 * [키로거]
 * 
 *  : 사용자가 키보드를 누른 명령을 모두 기록 (알파벳 대문자, 소문자, 숫자, 백스페이스, 화살표)
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {
    int t; // 테스트 케이스의 개수
    string s; //길이가 1 <= s <= 1,000,000인 문자열. 백스페이스는 -, 화살표는 < >

    //입력
    cin >> t;
    while (t--) {
        cin >> s;

        //연산 & 출력
        cout << findPass(s) << '\n';
    }
    return 0;
}