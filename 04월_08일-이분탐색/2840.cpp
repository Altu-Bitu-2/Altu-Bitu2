#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci;

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
    string ans = ""; //화살표가 가리키는 문자열
    int start = arrow_point; //특정 화살표 위치에서 시작
    do {
        //화살표 위치가 시작점이 아닐 동안
        ans += wheel[arrow_point]; //해당 화살표가 가리키는 알파벳을 더함
        arrow_point = (arrow_point + 1) % n; //인덱스 초기화
    } while (arrow_point != start);
    return ans;
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?'); //바퀴의 상태
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int idx = 0; //화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) {
        //record의 크기만큼 반복
        int rot = record[i].first; //회전 시켰을 때 화살표가 가리키는 글자가 몇 번 바뀌었는지
        char alpha = record[i].second; //회전을 멈추었을 때 가리키던 글자
        idx = (idx - rot % n + n) % n; //index 계산
        if (wheel[idx] == alpha) {
            //만약 가리키는 글자가 맞다면 다음 step으로
            continue;
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) {
            //바퀴가 ?가 아니거나 해당 알파벳이 이미 있다면, 해당 글자가 행운의 바퀴에 없음
            return "!";
        }
        wheel[idx] = alpha; //해당 위치에 알파벳 넣기
        is_available[alpha - 'A'] = true; //중복 체크
    }
    return arrowStartWheel(idx, n, wheel);
}

/**
 * [행운의 바퀴] : 바퀴에 같은 글자는 두 번 이상 등장하지 않음, 시계방향으로만 돌아감
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
    int n, k; //바퀴의 칸(2<=n<=25), 바퀴를 돌리는 횟수(1<=k<=100)

    //입력
    cin >> n >> k;
    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++) {
        // 바퀴 돌리는 횟수 k번 반복하여 바퀴를 회전시켰을 때 화살표가 가리키는 글자가 몇 번 바뀌었는지(frist)와 회전을 멈추었을 때 가리키던 글자(second) 입력
        cin >> record[i].first >> record[i].second;
    }

    //연산 & 출력
    cout << makeWheel(n, record);
    return 0;
}