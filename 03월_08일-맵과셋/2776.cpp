#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

//시간초과

int main()
{
    //입력 (1<=N<=1,000,000, 1<=M<=1,000,000)
    int t, n, m, input;
    cin >> t;

    while (t--){
        unordered_set<int> note;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            note.insert(input);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> input;
            //탐색하면서 입력한 것과 같은 수가 나오면 1 아니면 0
            if (note.find(input) != note.end()){
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }

}