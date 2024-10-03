#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int row, col;
int arr[1001][1001];
bool visited[1001][1001];
vector<pair<int, int>>tomato;
queue<pair<int, int>>q;
int step[1001][1001];

bool InRange(int x, int y) {
	return x >= 0 && x < row && y >= 0 && y < col;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && arr[x][y] != -1 && !visited[x][y];
}

void BFS() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		int dx[4] = { 0,0,-1,1 };
		int dy[4] = { 1,-1,0,0 };

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (CanGo(nx, ny)) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				step[nx][ny] = step[x][y]+1;
			}
		}

	}

}

int main() {
	bool test = true;
	int ans = 0;
	cin >> col >> row;
	int cnt_arr = 0;
	bool check1 = true;
	bool check2 = true;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				tomato.push_back(make_pair(i, j));
			else if (arr[i][j] == 0)
				check1 = false;
			else if (arr[i][j] == -1)
				cnt_arr++;

		}
	if (tomato.size() == 0) {
		cout << "-1";
	}
	else if (tomato.size() * cnt_arr == row * col || tomato.size() == row * col)
		cout << "0";
	else {
		for (int i = 0; i < tomato.size(); i++) {
			pair<int, int>curr_pos = tomato[i];
			int x = curr_pos.first, y = curr_pos.second;
			q.push(make_pair(x, y));
			visited[x][y] = true;
			step[x][y] = 0;
		}
		BFS();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j] == 0 &&!visited[i][j]) {
					test = false;
				}
				ans = max(ans, step[i][j]);
			
			}
			
		}
		if (test == false)
			cout << -1;
		else
			cout << ans;


	}
	
	return 0;
}