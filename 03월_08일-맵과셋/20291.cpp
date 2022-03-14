#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 결과는 나오지만, 틀렸습니다!!

int main() {
    //입력 
    //(1<= n <= 50,000)
    //(3<= filename <= 100)
    int n;
    cin >> n;

    map<string, int> file;
    vector<string> ext;

    //연산
    //1. 확장자 분리하기
    //2. 확장자 개수 세고 사전 순 정렬(오름차순)
    //3. 개수와 확장자명을 사전 순 출력
    while(n--){
        string file_name;
        cin >> file_name;

        //1. 확장자 분리하기
        file_name.erase(0, file_name.find('.') + 1);
        ext.push_back(file_name);
    }

    //2. 확장자 정렬한 뒤 개수 세기
    sort(ext.begin(), ext.end());
    for(int i=0; i < ext.size(); i++) {
        cout << ext[i] << "\n";
    }

    int cnt = 0;
    string tmp = ext[0];
    
    for(int i=0; i < ext.size(); i++) {
        
        if (tmp == ext[i]){
            cnt ++;
        } else {
            // 확장자가 다를 때, 그동안 셌던 cnt를 map에 넣음
            file[ext[i-1]] = cnt;
            cnt = 1;
            tmp = ext[i];
        }
        
    }
    //맨 마지막 넣기
    file[tmp] = cnt;


    //3. 확장자 수와 이름을 사전 순 출력
    map<string, int>::iterator iter;
    for(auto iter : file){
        cout << iter.first << " " << iter.second << '\n';
    }

    return 0;
}