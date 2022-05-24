#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401; //최댓값 20 * 20 + 1
typedef pair<int, int> ci; // 좌표를 입력할 타입

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    // bfs 탐색. 상 하 좌 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int min_dist = INF; // 최소 거리 초기화
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> dist(n, vector<int>(n, 0)); //상어의 방문 여부 + 거리
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1; //상어의 거리 초기화
    q.push(shark); //상어의 방문 체크
    while (!q.empty()) {
        //상어가 갈 수 있는 곳이 없을 때까지
        int row = q.front().first; //상어가 방문한 x좌표
        int col = q.front().second; // 상어가 방문한 y좌표
        q.pop(); //방문함

        if (dist[row][col] >= min_dist) { //최단거리 이상은 탐색할 필요 없음
            continue;
        }
        for (int i = 0; i < 4; i++) {
            //상하좌우 방문 탐색
            int nr = row + dr[i]; //행 계산
            int nc = col + dc[i]; //열 계산
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) {
                //공간을 벗어나거나 이미 방문하거나 상어의 크기보다 더 큰 물고기가 있다면 다음칸으로
                continue;
            }

            dist[nr][nc] = dist[row][col] + 1; //상어의 거리 증가
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); //물고기 추가
                min_dist = dist[nr][nc]; //최소거리 갱신
                continue;
            }
            q.push({nr, nc}); //다음에 위치할 상어 좌표
        }
    }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}}; //최소 거리와 좌표 리턴
    }

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) {
            //x좌표가 다르다면, 더 큰 값 리턴(오름차순)
            return p1.first < p2.first;
        }
        return p1.second < p2.second; //x좌표가 같으면 y좌표가 더 큰 값 리턴
    });
    return {min_dist - 1, list[0]}; //최소 거리와 가장 작은 좌표 리턴
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0;
    //ans : 아기 상어가 최대로 잡아먹는 초(시간)
    //size : 상어의 크기
    // cnt : 초 카운트
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board); // 상어가 다음으로 갈 위치
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;
        }
        ans += result.first; //시간 더하기
        cnt++; //초 +1
        if (cnt == size) { //상어 크기 증가
            cnt = 0; //초 초기화
            size++; //상어 크기 증가
        }

        //상어 이동
        board[shark.first][shark.second] = 0; //빈 칸으로 만듦
        shark = result.second; //이동한 위치 좌표
    }
    return ans;
}

/**
 * [아기 상어]
 *
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */

int main() {
    int n; //공간의 크기 2<=n<=20
    pair<int, int> shark_pos; //아기 상어의 위치 좌표

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n)); // 공간
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //공간의 상태 입력. 0, 9을 제외하면 물고기의 크기 의미
            if (board[i][j] == 9) { //상어의 초기 위치
                shark_pos = make_pair(i, j);
            }
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
    return 0;
}