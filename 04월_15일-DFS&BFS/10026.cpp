#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci; //좌표를 입력하는 int pair

//단지 내 집 개수 탐색하는 bfs
int bfs(int n, int r, int c, vector<vector<bool>> &board) {
    //상하좌우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q; //방문을 위한 큐

    //큐 초기화
    q.push({r, c}); //해당 칸 push
    board[r][c] = false; //방문하지 않음
    int cnt = 1; //단지 수
    while (!q.empty()) {
        int cr = q.front().first; //현재 좌표 행
        int cc = q.front().second; //현재 좌표 열
        q.pop(); //방문한 단지 제외

        for (int i = 0; i < 4; i++) {
            //상하좌우 방문
            int nr = cr + dr[i]; //현재 좌표 행에서 상하좌우
            int nc = cc + dc[i]; //현재 좌표 열에서 상하좌우
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || !board[nr][nc]) {
                //지도밖으로 벗어났거나 해당 칸이 이미 방문했다면 다음 칸으로
                continue;
            }
            q.push({nr, nc}); //현재 방문한 좌표 push
            board[nr][nc] = false; //해당 좌표 초기화
            cnt++;//단지내 집의 수 증가
        }
    }
    return cnt; //단지 내 집의 개수 리턴
}

//단지 수와 단지 내 집 개수 구하는 함수
vector<int> cntComplex(int n, vector<vector<bool>> &board) {
    vector<int> complex; //단지 벡터
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //지도 크기만큼 반복
            if (board[i][j]) {
                //만약 해당 칸이 0이 아니라면
                int cnt = bfs(n, i, j, board); //bfs방문
                complex.push_back(cnt); //단지 추가
            }
        }
    }
    return complex; //단지 리턴
}

/**
 * [단지 번호 붙이기] - bfs
 *
 * 단순 탐색
 * (주의) 단지 내 집의 수를 "오름차순"으로 출력
 *
 * 이 풀이에서는 방문체크 배열을 따로 사용하지 않고, 처음 지도에 표기를 1 -> 0으로 바꾸어 중복으로 탐색하지 않도록 함
 */

int main() {
    int n; //지도의 크기 5<=n<=25
    string s; //0 혹은 1로 이루어진 n개의 자료

    //입력
    cin >> n; //지도의 크기 입력
    vector<vector<bool>> board(n, vector<bool>(n, false)); //지도를 입력한 2차원 벡터
    for (int i = 0; i < n; i++) {
        //지도의 크기만큼 n개의 자료 입력
        cin >> s;
        for (int j = 0; j < n; j++) {
            //n개만큼 반복하며 0혹은 1 입력
            board[i][j] = s[j] - '0';
        }
    }

    //연산
    vector<int> ans = cntComplex(n, board);//단지 수와 단지 내 집의 개수 입력
    sort(ans.begin(), ans.end());

    //출력
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}