#include<iostream>
#include<queue>

using namespace std;

int n;

int arr[100][100];
int arr2[100][100];
queue<pair<int, int>>q;
bool visited[100][100];

bool InRange(int x, int y) {
	
		return x >= 0 && x < n && y >= 0 && y < n;
	
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y];
}
void BFS() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		int dx[4] = { 0,0,-1,1 };
		int dy[4] = { 1,-1,0,0 };
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			for (int i = 0; i < 4; i++) {
				if (CanGo(nx, ny) && arr[x][y] == arr[nx][ny]) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}



void BFS2() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		int dx[4] = { 0,0,-1,1 };
		int dy[4] = { 1,-1,0,0 };
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			for (int i = 0; i < 4; i++) {
				if (CanGo(nx, ny) && arr2[x][y] == arr2[nx][ny]) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}




int main() {
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == 'R') {
				arr[i][j] = 0;
				arr2[i][j] = 0;
			}
			else if (c == 'G') {
				arr[i][j] = 1;
				arr2[i][j] = 0;
			}
			else {
				arr[i][j] = 2;
				arr2[i][j] = 2;
			}
		}
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			if (CanGo(i, j)) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
				cnt++;
						BFS();
			}
		}
	cout << cnt<<" ";

	cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}



	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (CanGo(i, j)) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
				cnt++;
				BFS2();
			}
		}
	cout << cnt;





	return 0;
}