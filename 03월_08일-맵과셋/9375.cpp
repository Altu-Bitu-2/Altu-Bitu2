#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    //입력 (t <100, 0<=n<=30)
    int t, n;
    cin >> t;

    
    map <string, int> :: iterator iter;
    
    //연산
    // 같은 종류의 의상은 하나만 있어야 한다.
    // 1. 종류 별로 count하고 경우의 수를 계산한다.
    // 2. 경우의 수는 0개, 1개, ..., n-1개, n개 이므로 (n+1) * (n+1) - 1(알몸)이다.

    while(t--){
        cin >> n;
        map <string, int> clothes; // 기존 내용 삭제
        while(n--){
            string category, name;
            cin >> name >> category;

            //find 함수는 찾는 key가 없으면 end를 return한다.
            if (clothes.find(category) == clothes.end()) {
                clothes[category] = 1;
            } else {
                clothes[category]++;
            }
        }

        int sum = 1;
        for( auto iter : clothes){
            sum *= (iter.second + 1) ;
        }

        sum -= 1;

        cout << sum << "\n" ;
    }

    
    
   return 0;
}