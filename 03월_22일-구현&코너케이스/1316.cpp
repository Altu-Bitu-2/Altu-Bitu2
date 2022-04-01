#include <iostream>
#include <vector>

using namespace std;

// 그룹 단어 체커 : 연속해서 나타나는 글자 묶음
bool isGroup(string word){
    char cur = NULL; //현재 문자
    vector<bool> alphabet(26, false); // 각 알파벳의 등장 여부를 체크

    for (int i=0; i<word.size(); i++){
        if(word[i] == cur){
            //연속해서 나타난 숫자
            continue;
        }

        //이전의 문자와 다른 문자가 나타났을 때
        if (alphabet[word[i] - 'a']){
            //이전에 등장했던 문자면 떨어져서 나타난 것
            return false;
        }

        cur = word[i]; //현재 문자 갱신
        alphabet[word[i] - 'a'] =true; //알파벳 등장 여부 체크
    }

    return true;
}

int main() {
    //입력
    int n; // n <= 100
    int result = 0; //개수를 입력
    cin >> n;

    while(n--){
        string word;
        cin >> word;

        //연산
        if (isGroup(word)){
            //그룹 단어인지 확인
            result++;
        }
    }

    //출력
    cout << result;

    return 0;

}