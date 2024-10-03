#include<iostream>
#include<queue>
#include<string>

using namespace std;

int n, m;
int arr[100][100];
queue<pair<int, int>>q;
bool visited[100][100];
int step[100][100];

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && arr[x][y]==1;
}

void BFS() {
	while (!q.empty()) {
	
		pair<int, int>curr_pos = q.front();
		int x = curr_pos.first, y = curr_pos.second;
		int dx[4] = { 0,0,-1,1 };
		int dy[4] = { 1,-1,0,0 };
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			
			if (CanGo(nx, ny)) {
				step[nx][ny] = step[x][y] + 1;
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}

}

int main() {
	cin >> n >> m;	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j]-48;
		}
	}
	visited[0][0] = true;
	q.push(make_pair(0, 0));
	step[0][0] = 1;
	BFS();

	cout << step[n - 1][m - 1];
	return 0;
}