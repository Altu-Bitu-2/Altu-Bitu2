#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxTip(int n, vector<int> &tip)
{
    int t;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        t = tip[i] - i;
        if (t < 0)
        {
            t = 0;
        }
        
        max += t;
    }
    return max;
}

int main()
{
    int n;
    cin >> n;

    vector<int> tip(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> tip[i];
    }

    //연산
    sort(tip.begin(), tip.end(), greater<>());
    cout << maxTip(n, tip);
}