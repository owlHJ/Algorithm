#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;


int arr[300][300];
int step[300][300];
bool visited[300][300];
queue<pair<int, int>>q;


bool InRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}


bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y];
}

void BFS() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
		int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };


		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (CanGo(nx, ny)) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				step[nx][ny] = step[x][y] + 1;
			}
		}
		
	}
}
void Start() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			step[i][j] = 0;
		}
			
}


int main() {
	int T;
	int x1, x2;
	int y1, y2;
	cin >> T;
	while (T--) {
		Start();

		cin >> n;
		cin >> x1 >> y1;
		cin >> x2 >> y2;

		if (x1 == x2 && y1 == y2) {
			cout << "0" << endl;
		}
		else {
			q.push(make_pair(x1, y1));
			step[x1][y1] = 0;
			visited[x1][y1];

			BFS();
			cout << step[x2][y2] << endl;
		}

		

	}


	return 0;
}