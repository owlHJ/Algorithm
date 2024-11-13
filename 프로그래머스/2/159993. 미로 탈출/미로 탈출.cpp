#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
    int x;
    int y;
};

struct queueInfo {
    Pos pos;
    int iCnt;
};

int board[100][100];
int n, m;  // 미로 크기
Pos posStart, posEnd, posLever;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 범위 확인 함수
bool InRange(const int &x, const int &y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// 미로 설정 함수
void BoardInit(const vector<string> &maps) {
    n = maps.size();
    m = maps[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            switch (maps[i][j]) {
                case 'S':
                    board[i][j] = 3;
                    posStart = {i, j};
                    break;
                case 'E':
                    board[i][j] = 4;
                    posEnd = {i, j};
                    break;
                case 'L':
                    board[i][j] = 5;
                    posLever = {i, j};
                    break;
                case 'O':
                    board[i][j] = 0;
                    break;
                case 'X':
                    board[i][j] = 1;
                    break;
            }
        }
    }
}

// BFS 함수
int BFS(Pos start, Pos end) {
    queue<queueInfo> q;
    bool visited[100][100] = {false};

    q.push({start, 0});
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        queueInfo qTemp = q.front();
        q.pop();

        if (qTemp.pos.x == end.x && qTemp.pos.y == end.y) {
            return qTemp.iCnt;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = qTemp.pos.x + dx[i];
            int ny = qTemp.pos.y + dy[i];

            if (!InRange(nx, ny) || board[nx][ny] == 1 || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({{nx, ny}, qTemp.iCnt + 1});
        }
    }
    return -1;  // 도달 불가능할 때 -1 반환
}

// 솔루션 함수
int solution(vector<string> maps) {
    BoardInit(maps);

    // 출발점에서 레버까지 거리 계산
    int cntToLever = BFS(posStart, posLever);
    if (cntToLever == -1) return -1;

    // 레버에서 출구까지 거리 계산
    int cntToExit = BFS(posLever, posEnd);
    if (cntToExit == -1) return -1;

    return cntToLever + cntToExit;
}
