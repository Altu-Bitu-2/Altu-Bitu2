#include <iostream>
#include <vector>

using namespace std;

vector<int> card;


void reverse(int a, int b)
{
    while (a < b)
    {
        swap(card[a++], card[b--]);
    }
}

int main()
{
    vector<int> a(10, 0);
    vector<int> b(10, 0);

    card.assign(20, 0);

    for (int i = 0; i<10 ; i++) {
        cin >> a[i] >> b[i];
    }
    
    for (int i = 0; i < 20; i++)
    {
        card[i] = i + 1;
    }

    for (int i = 0; i<10 ; i++) {
        reverse(a[i] - 1, b[i] - 1);
    }

    for (int i = 0; i < 20; i++)
    {
        cout << card[i] << " ";
    }
}