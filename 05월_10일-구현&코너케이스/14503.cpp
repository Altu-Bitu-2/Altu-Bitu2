#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) {
    //상, 우, 하, 좌
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int step = 0, ans = 0; //회전 카운트 step, 청소하는 칸 ans
    while (true) { //무한루프
        if (board[r][c] == 0) {
            //현재 칸이 빈칸이라면
            board[r][c] = 2; //청소함
            ans++; //청소한 칸 +1
        }

        if (step == 4) {
            //로봇 청소기가 한 바퀴 돌았음
            if (board[r - dr[d]][c - dc[d]] == 1) {
                //다음 칸이 벽이라면 ans 리턴
                return ans;
            }
            r -= dr[d]; //다음 칸 행
            c -= dc[d]; //다음 칸 열
            step = 0; //회전수 초기화
        } else {
            //아직 한 바퀴 돌지 않았다면
            d = (d + 3) % 4; //다음 방향
            if (board[r + dr[d]][c + dc[d]]) {
                //만약 다음 칸이 벽이면(1)
                step++; //회전 수 증가
                continue; //다음 단계로
            }
            r += dr[d]; //다음 칸 행
            c += dc[d]; //다음 칸 열
            step = 0; //회전수 초기화
        }
    }
}

/**
 * [로봇 청소기]
 *
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    //3<= 행m, 열n <= 50
    //로봇청소기의 좌표(r, c)
    //바라보는 방향 d
    int n, m, r, c, d;

    //입력
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> board(n, vector<int>(m, 0)); //장소 NxM
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //지도 상태 입력
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;
}