#include <iostream>
#include <vector>

using namespace std;

/**
 * 골드바흐의 추측
 * 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
 *  : 백만 이하의 모든 짝수에 대해서, 이 추측을 검증하는 프로그램을 작성하시오.
 * 
 */

const int SIZE = 1e6; //정수 최댓값

//에라토스테네스의 체, 미리 SIZE까지의 소수 판단
vector<bool> isPrime() {
    vector<bool> is_prime(SIZE + 1, true); //소수 판단 여부 저장

    //0과 1은 소수가 아님
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= SIZE; i++) {
        if (!is_prime[i]) { //소수가 아니라면
            continue;
        }
        //i가 소수라면
        for (int j = i * i; j <= SIZE; j += i) {
            is_prime[j] = false; //i의 배수 제거함
        }
    }
    //소수 판단 배열 리턴
    return is_prime;
}

//골드바흐의 추측 판단 함수
int checkGoldbach(int n, vector<bool> &is_prime) {
    //홀수만 검사한다
    // n/2 이상의 값은 어차피 n-i를 통해 검사되므로 n/2까지 검사
    for (int i = 3; i <= n / 2; i += 2) { 
        // 두 홀수가 모두 소수라면 (추측이 맞음)
        if (is_prime[i] && is_prime[n - i]) { 
            return i; //두 홀수 소수 중 작은 값 리턴
        }
    }
    return 0; //골드바흐의 추측이 틀린 경우
}

int main () {
    //테스트 케이스 <=100,000
    //짝수 정수 6<= n <= 1,000,000

    ios_base::sync_with_stdio(false); //입출력 속도 향상
    cin.tie(NULL);

    int n;
    vector<bool> is_prime = isPrime(); //소수 판단 여부 저장

    //테스트 케이스가 0이 나오지 않을 때까지
    while(true){
        //입력
        cin >> n;
        if(n == 0){
            break;
        }

        //연산
        int prime = checkGoldbach(n, is_prime); //골드바흐 추측이 맞는지
        if(prime){
            //맞다면 -> 두 홀수 소수 중에서 작은 값을 리턴받음
            cout << n << " = " << prime << " + " << n-prime << "\n";
        } else {
            //틀리다면 -> 0을 리턴받음
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}