#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<tuple>
using namespace std;
vector<pair<int, int>>people;
pair<int, int> score[50];
int answer[50];

bool Fun(pair<int, int>a, pair<int, int>b) {
	return a.first < b.second;
}

int m, n;
int arr[50][50];
int test[50][50];
bool visited[50][50];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
queue<pair<int, int>> fish;
queue<tuple<int, int, int>>q1;
int countnum = 0;

void Showmap() {
	cout << countnum << "번째 " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool CanGo(int nx, int ny) {
	return nx >= 0 && nx < m && ny >= 0 && ny < n ;
}
void BFS() {
	//q1.push({ a,b,0 });
	//test[a][b] = 2;

	while (!q1.empty()) {
		
		int x, y, cnt;
		tie(x, y, cnt) = q1.front();
		countnum = cnt;
		q1.pop();
		
	//	cout << countnum << "번째  -> " <<x<<" , "<<y <<"q size : "<<q1.size() << endl;
	//	Showmap();
		//test[x][y] = 2;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (CanGo(nx, ny) && !visited[nx][ny]) {
				q1.push({ nx,ny,cnt + 1 });
				visited[nx][ny] = true;
			}
		}
	}


}

void Set() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			test[i][j] = arr[i][j];
			visited[i][j] == false;
		}
	}
	while (!q1.empty())q1.pop();
}
int main() {

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				//fish.push(make_pair(i, j));
				q1.push({ i, j,0 });
				visited[i][j] = true;
			}
		}
	}
	int max_num = 0;
	BFS();
	cout << countnum;
	//cout << max_num;
	return 0;
}