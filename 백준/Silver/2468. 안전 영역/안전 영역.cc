#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<queue>
#include<tuple>

using namespace std;



int n;
bool visited[101][101];
int arr[101][101];
int cnt;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>>q1;
void ShowBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << " ";
		}cout << endl;
	}cout << endl;
}
void Set(int high) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] >= high) {
				visited[i][j] = false;
			}
			else visited[i][j] = true;
		}
	cnt = 0;
}
bool CanGo(int x , int y) {
	return x >= 0 && x < n && y >= 0 && y < n && !visited[x][y];
}
void BFS() {
	int x, y;
	

	while (!q1.empty()) {

		tie(x, y) = q1.front();
		q1.pop();


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (CanGo(nx, ny)) {
				visited[nx][ny] = true;
				q1.push({ nx,ny });
			}
		}

	}

}


int main() {
	cin >> n;
	int k = 0;
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (k < arr[i][j])k = arr[i][j];
		}
	}
		
	//cout << k;
	for (int i = k; i >= 1; i--) {
		Set(i);
	//	ShowBoard();
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (CanGo(a,b)) {
					visited[a][b]=true;
					q1.push({ a,b });
					BFS();
					cnt++;
				}
			}
		}
		max_num = max(max_num, cnt);
	}
	cout << max_num;
	


	return 0;
}