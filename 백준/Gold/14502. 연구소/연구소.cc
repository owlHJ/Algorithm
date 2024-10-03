#include<iostream>
#include<queue>
#include<vector>


// 0빈칸, 1벽 2, 바이러스

using namespace std;

int n, m;
int arr[1000][9];
bool visited[1000][9];
int temp[1000][9];
vector<pair<int, int>>virous;
vector<pair<int, int>>block;
queue<pair<int, int>>q;

int ans = 0;
//안전 구역 구하기
void Start() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
			temp[i][j] = arr[i][j];
		}

}
bool InRange(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && arr[x][y] != 1;
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
				temp[nx][ny] = 2;
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int Calc() {
	int cnt = 0;
	
	Start();
	for (int i = 0; i < virous.size(); i++) {
		int x = virous[i].first, y = virous[i].second;
		q.push(make_pair(x, y));
		visited[x][y] = true;

	}
	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0)cnt++;
		}
	}

	/*
			if (cnt > ans) {
				cout << cnt<<" " << endl;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						cout << temp[i][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
*/
		
		//계산 끝나고 벽 다시 재위치 해야함
	

	return cnt;
}


void Back(int num) {

	if (num == 3) {
		
		ans = max(ans, Calc());
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				Back(num + 1);
				arr[i][j] = 0;
			}

			
		}


	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) {
				virous.push_back(make_pair(i, j));
			}

		}

	Back(0);


	cout << ans;




	return 0;
}