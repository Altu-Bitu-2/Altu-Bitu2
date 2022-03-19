#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int calc(string s) {
    stack<char> st; //괄호를 넣을 스택
    map<char, int> num; //괄호 값
    map<char, char> bracket; //괄호 쌍

    //괄호 쌍과 값 저장
    bracket[')'] = '(';
    bracket[']'] = '[';
    num['('] = 2;
    num['['] = 3;

    //괄호를 연산할 ans, 임시변수 temp
    int ans = 0, temp = 1;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '(': case '[': //여는 괄호일 경우 스택에 넣고 괄호 값 계산
                st.push(s[i]);
                temp *= num[s[i]];
                break;
            case ')': case ']': //닫는 괄호일 경우
                //스택이 비어있거나 top이 여는 괄호가 아니면 종료
                if (st.empty() || st.top() != bracket[s[i]]) {
                    return 0;
                }
                //이전 괄호가 여는 괄호쌍일 경우 temp를 ans에 더함
                if (s[i - 1] == bracket[s[i]]) {
                    ans += temp;
                }
                temp /= num[bracket[s[i]]]; //이미 값을 더한 경우이므로 나누기
                st.pop();
                break;
        }
    }

    //괄호 쌍이 올바르게 제거되었다면
    if (st.empty()) {
        return ans;
    }
    //아니면 0리턴
    return 0;
}

/**
 * "분배법칙"을 활용!
 * ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 * =>                               (   [ ]     (   [   ]   )   )
 * =>                   임시변수값:  2   6 2     4  12   4   2   1
 * =>                        정답:        +6           +12        = 18
 *
 * 따라서, 우선 여는 괄호가 나오면 괄호의 값을 곱해줌
 * 닫는 괄호는, 이전 문자가 여는 괄호일 경우 지금까지 곱한 값을 더해줌 (값이 중복으로 더해지는 것을 방지하기 위해 이전 문자가 여는 괄호인지 꼭 체크!)
 *            한 괄호에 대한 연산이 끝났으므로 (곱하기 연산) 다시 괄호 값을 나눠줘서 연산 진행
 */

int main() {
    //1<=s<=30
    string s;

    //입력
    cin >> s;
    //연산 & 출력
    cout << calc(s);
    return 0;
} 