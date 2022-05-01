#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct coor
{
    int x, y;
};

bool cmp(const coor &a, const coor &b){
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y < b.y;
}


int main()
{
    int n;
    cin >> n;
    vector<coor> crd(n);

    for (int i = 0; i < n; i++)
    {
        cin >> crd[i].x >> crd[i].y;
    }

    //연산
    sort(crd.begin(), crd.end(), cmp);

    //출력
    for (int i = 0; i < n; i++)
    {
        cout << crd[i].x <<" "<< crd[i].y << "\n";
    }
}