#include <iostream>
#include <stack>

using namespace std;

//A+B함수, 일의 자릿수부터 더함
stack<int> calcPlus(string &a, string &b){
    stack<int> st;
    int p1 = a.length() -1; //a의 일의 자릿수 인덱스
    int p2 = b.length() -1; //b의 일의 자릿수 인덱스
    bool carry = false; //올림 체크 변수

    while(p1 >= 0 && p2 >= 0){
        //자릿수 더하기
        int num = (a[p1--] - '0') + (b[p2--]-'0'); //a와 b의 각 자릿수 값 더하기
        num += carry; //올림이 있으면 1더함
        carry = num /10; //자릿수 더한 값이 10을 넘으면 올림변수 체크
        st.push(num%10); //올림값 제외한 값을 넣어줌

    }

    while(p1 >= 0){
        //a에서 남은 숫자 반영
        int num = (a[p1--] - '0'); //a의 해당 자릿수 값
        num += carry;
        carry = num /10;
        st.push(num%10);

    }
    if (carry){
        //마지막 올림 확인
        st.push(1);
    }

    return st;
}

int main() {
    //입력
    //a, b의 최댓값이 1e10000이므로 string에 저장
    string a, b;
    cin >> a >> b;

    stack<int> st; //더한 결과값을 저장할 스택

    // 연산
    if (a.length() < b.length() ){
        //만약 b의 길이가 더 길다면
        //a의 길이가 더 길도록 swap
        swap(a, b);
    }
    st = calcPlus(a,b);

    //출력
    while(!st.empty()){
        //스택 순회
        cout << st.top();
        st.pop();
    }
    cout << "\n";

    return 0;
}