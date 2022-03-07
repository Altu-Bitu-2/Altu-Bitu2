#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 테스트 결과는 똑같이 나왔으나 백준에선 틀렸다고 나옴

void minS(vector<int> &a, vector<int> &b, int n)
{
    //가장 작은 값과 가장 큰 값을 곱하면 최솟값이 나오지 않을까?
    //그 다음 작은 값과 그 다음 큰 값을 만나도록 짜려면?
    // a를 오름차순으로 정렬한 뒤 b의 가장 큰 값의 인덱스를 찾아 a의 첫 번째 원소부터 짝을 맺게 하면 되지 않을까?
    vector<int> tmp1 = a;
    vector<int> tmp2 = b;
    sort(tmp1.begin(), tmp1.end());

    int max_a = 0, max_b = 0, max_index = 0, min_index = 0;
    int min_a = a[0], min_b = b[0];

    for (int i = 0; i < n; i++) // a 원소를 순서대로 바꿈
    {
        for (int j = 0; j < n; j++) 
        {
            if (max_b < tmp2[j])
            {
                max_b = tmp2[j];
                max_index = j;
            }
        }

        a[max_index] = tmp1[i];

        tmp2[max_index] = 0;
        max_b = 0;
    }

    //합 구하기
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }

    cout << sum;
}

int main()
{
    //입력
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    //연산
    minS(a, b, n);
}