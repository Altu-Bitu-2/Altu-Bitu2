#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N <= 100,000 (자연수)
// tip <= 100,000 (자연수)

//최댓값을 가정해보면 약 150억이 나온다. (맞나요..?)
//int형은 signed int형일 경우 20억(unsigned int는 40억)까지밖에 표현을 못하기 때문에 long long 타입을 사용해야 한다.
long long maxTip(int n, vector<int> &tip)
{
    int t;
    long long max = 0;
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