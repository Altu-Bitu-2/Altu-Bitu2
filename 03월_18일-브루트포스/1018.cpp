#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 64; //체스판 칸 개수

//(x, y)에서 시작하는 8*8(64) 체스판을 만드는데 필요한 최소 카운트 리턴
//검정으로 시작하는 체스판을 기준으로 계산(b_count) -> 절반(32) 이상이면 흰색으로 시작하는 체스판 카운트(64 - b_count) 리턴
int chessChange(int row, int col, vector<vector<char>> &board) {
    int b_cnt = 0; //B로 시작하는 체스판 만들기 위한 카운트

    for (int i = 0; i < 8; i++) { //행 변화값
        for (int j = 0; j < 8; j++) { //열 변화값
            //인덱스 i + j가 짝수면 'B'
            if ((i + j) % 2 == 0 && board[row + i][col + j] != 'B') {
                b_cnt++;
            } else if ((i + j) % 2 && board[row + i][col + j] != 'W') {
                //인덱스 i+j가 홀수면 'W'
                b_cnt++;
            }

        }
    }

    //최솟값 리턴
    if (b_cnt > SIZE / 2) {
        //체스판의 절반보다 검정이 많으면
        return SIZE - b_cnt;
    }
    return b_cnt;
}

int main() {
    int n, m; // 체스판의 크기
    //정답(다시 칠해야 하는 정사각형 개수)은 체스판 칸 개수 + 1 로 초기화
    int ans = SIZE + 1; 

    //입력
    cin >> n >> m;
    //행: n, 열: m <2차원 벡터>
    vector<vector<char>> board(n, vector<char>(m)); 
    for (int i = 0; i < n; i++) { //보드 입력
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산
    //8*8체스판 제외하고 반복
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            //시작인덱스가 (i,j)인 체스판 만드는 최솟값
            int cnt = chessChange(i, j, board); 
            ans = min(ans, cnt); //최솟값 갱신
        }
    }

    //출력
    cout << ans << '\n';
    return 0;
}