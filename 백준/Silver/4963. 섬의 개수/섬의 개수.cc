#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int arr[100][100];
bool visited[100][100];
queue<pair<int, int>>q;

	int row, col;

void Start() {
	for(int i=0;i<row;i++)
		for (int j = 0; j < col; j++) {
			visited[i][j] = false;
			arr[i][j] = 0;
		}

}

bool InRange(int x, int y) {
	return x >= 0 && x < row&& y >= 0 && y < col;
}

bool CanGo(int x, int y) {
	
	return InRange(x, y) && !visited[x][y] && arr[x][y];

}
void BFS() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		int dx[8] = { -1,-1,-1,0,1,1,1,0 };
		int dy[8] = { -1,0,1,1,1,0,-1,-1 };
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (CanGo(nx, ny)) {
				q.push(make_pair(nx, ny));
				visited[nx][ny]=true;
			}
		}
	
	}
	
}

int main() {
	cin >> col >> row;
		bool test = true;
		while (test) {
			int cnt = 0;

			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					cin >> arr[i][j];

			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++) {
					if (CanGo(i, j)) {
						q.push(make_pair(i, j));
						visited[i][j] = true;
						BFS();
						cnt++;
					}

				}


			cout  << cnt<<endl;

			Start();
			cin >> col >> row;
			if (row == 0 && col == 0)
				test = false;
			
		}


	return 0;
}