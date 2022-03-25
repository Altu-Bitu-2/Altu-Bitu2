#include <iostream>
#include <vector>

using namespace std;

// 민트초코
// : 곱셈과 나눗셈으로만 이뤄진 임의의 수식의 결과가 정수면 "민트 초코" mint chocholate
// : 정수가 아닌 유리수이면 "치약" toothpaste

/**
 * @brief
 *  수는 소인수분해하여 나타낼 수 있고, 지수가 음수인 소인수가 하나라도 존재한다면 유리수
 *  문제의 수식은 * , / 만 들어온다
 * 따라서, 문제의 수식대로 계산하는 과정에서 소인수의 지수를 저장
 * ** 정수 유리수 판단에서는 부호가 상관 없음 -> 모두 양수로 해서 계산
 * ** 0이 곱해지는 경우 무조건 정수이므로 예외 처리
 * @return int
 */

const int MAX = 1e5; // 최댓값 100,000

vector<int> prime(MAX + 1, 0);    //소수 경로 저장
vector<int> exponent(MAX + 1, 0); // 연산 과정에서 각 소수의 지수 저장

//소수 경로를 저장해서 리턴
void isPrime()
{
    // n이하의 수를 소인수분해하는 경로를 저장
    for (int i = 2; i * i <= MAX; i++)
    {
        //소수가 아니라면 continue
        if (prime[i] != 0)
        {
            continue;
        }
        // i가 소수라면
        // i부터 i*(i-1)은 이미 앞선 소수에 의해 지워짐
        for (int j = i * i; j <= MAX; j += i)
        {
            //배수에 소수 i 저장
            if (prime[j] == 0)
            {
                prime[j] = i;
            }
        }
    }
}

//소인수분해해서 지수 계산하는 함수
void countExponent(int a, int cnt)
{
    while (prime[a])
    {
        //소인수분해, prime[a] = 소인수
        exponent[prime[a]] += cnt; //연산이 곱하기라면 cnt = 1이어서 지수 증가, 나누기라면 cnt -1로 지수 감소
        a = a / prime[a];          // 지수 계산
    }
    exponent[a] += cnt; //마지막 남은 소수
}

//연산이 끝난 후, 소인수의 지수에 음수가 있는지 판단하고 있으면 유리수 (true)
bool isRationalNumber()
{
    for (int i = 2; i <= MAX; i++)
    {
        if (exponent[i] < 0)
        {
            //유리수라면
            return true;
        }
    }
    //음수가 없으므로 유리수가 아님
    return false;
}

int main()
{
    int n, a;
    char c;

    isPrime(); //소수 경로 저장
    // 입력
    cin >> n; //수식을 이루는 수의 개수
    cin >> a; //처음 수를 미리 입력

    if (a == 0)
    {
        //처음 수가 0이면 결과 값이 0 -> 정수이므로 바로 민트초코 출력
        cout << "mint chocolate\n";
        return 0;
    }

    countExponent(abs(a), 1); //처음 수는 곱하기로 계산

    //(수식 + 수)쌍으로 (n-1)개 입력 + 연산
    for (int i = 1; i < n; i++)
    {
        cin >> c >> a;

        if (a == 0)
        {
            // 0을 곱하면 결과값이 0이므로 정수
            cout << "mint chocolate\n";
            return 0;
        }

        if (c == '*')
        {
            //곱하기라면 지수 증가
            countExponent(abs(a), 1); // 2번째 매개변수 : 지수의 증가값
        }
        else
        {
            //나누기라면 지수 감소
            countExponent(abs(a), -1); // 2번째 매개변수 : 지수의 감소값
        }
    }

    //유리수인 경우
    if (isRationalNumber())
    {
        cout << "toothpaste\n";
    }
    else
    {
        // 0을 제외한 정수인 경우
        cout << "mint chocolate\n";
    }
    return 0;
}