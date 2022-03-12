#include <iostream>
#include <vector>

using namespace std;

void query(int T, int c, int &total)
{
    if (T == 1)
    {
        total = total + c;
        if ( total >= 86400) { //하루가 넘어감
            total = total % 86400;
        }
    }
    else if (T == 2)
    {
        total = total - c;
        if ( total < 0){ //전날로 넘어감
            total = total % 86400;
            total = 86400 + total;
        }
    }
    else
    {
        int h_ = total / 3600;
        int m_ = total % 3600 / 60;
        int s_ = total % 3600 % 60;
        cout << h_ << " " << m_ << " " << s_ << "\n";
    }
}

int main()
{
    //현재 시간
    int h, m, s, total;
    cin >> h >> m >> s;

    total = h * 3600 + m * 60 + s;

    //쿼리 개수
    int q;
    cin >> q;

    //쿼리
    int T, c;
    for (int i = 0; i < q; i++)
    {
        cin >> T;
        if (T != 3)
        {
            cin >> c;
            query(T, c, total);
        }
        query(T, 0, total);
    }
}