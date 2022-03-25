#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//n을 보고 30의 배수중 가장 큰 수를 구하기
/**
 * 30의 배수 = 10의 배수 * 3의 배수
 * 1. 10의 배수 = 입력된 수에 0이 포함되어 있는지 확인
 * 2. 3의 배수 = 모든 자리의 수의 합이 3의 배수인지 확인
 * 
 * 30의 배수임이 확인되었으면 가장 큰 수를 만들기 위해 9부터 0까지 역순으로 나열
 */

string findNum(string s){
    //0이 존재하는지 확인
    bool isTen = false;
    //3의 배수인지 확인하기 위한 용도의 합
    int sum = 0;

    // 돌면서 3의 배수와 10의 배수인지 확인
    for(int i=0; i<s.length(); i++){
        // 3의 배수인지 확인하기 위해 합을 구함
        sum += (s[i] - '0');

        // 만약 0이 포함되어 있으면 10의 배수임
        if(s[i] == '0') {
            isTen = true;
        }
    }

    // 3의 배수가 아니거나 10의 배수가 아니면 30의 배수가 아님
    if (sum % 3 != 0 || !isTen){
        return "-1";
    }

    //가장 큰 수를 만들기 위해 내림차순 정렬
    sort(s.begin(), s.end(), greater<>());

    return s;
}


int main () {
    //입력 0 < s <= 1e5
    string s;
    cin >> s;

    //연산 및 출력
    cout << findNum(s);

    return 0;
}