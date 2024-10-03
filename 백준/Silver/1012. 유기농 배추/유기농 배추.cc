#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int T, c, r,k;
vector<pair<int, int>>pos;
int arr[100][100];
bool visited[100][100];
queue<pair<int, int>>q;


void Start() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++){
			visited[i][j] = false;
			arr[i][j] = false;
		}
			

	pos.clear();


				
}
bool InRange(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && arr[x][y] ==1 && !visited[x][y];
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> curr_pos = q.front();
		int x = curr_pos.first, y = curr_pos.second;
		q.pop();
		int dx[4] = { 0,0,-1,1 };
		int dy[4] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (CanGo(nx, ny)) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));

			}
		}
		
	}
}

int main() {
	int cnt = 0;
	cin >> T;
	while (T--) {
		cin >> c >> r >> k;
		Start();
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> y >> x;
			pos.push_back(make_pair(x, y));
			arr[x][y] = 1;
		}

	
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if (CanGo(i, j)) {
					cnt++;
					visited[i][j] = true;
					q.push(make_pair(i, j));
					BFS();
				}
				
			}
		cout << cnt << endl;
		cnt = 0;
	}



		return 0;

}