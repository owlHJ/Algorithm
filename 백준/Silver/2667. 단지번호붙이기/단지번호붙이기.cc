#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
int arr[100][100];
bool visited[100][100];
queue<pair<int, int>>q;
vector<int> house;
bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y]&& arr[x][y];
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
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				house[house.size() - 1]++;
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {

		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			arr[i][j]=s[j]-48;

	}
	
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			if (CanGo(i, j)) {
				visited[i][j] = true;
				q.push(make_pair(i, j));
				house.push_back(1);
				BFS();
			}
		}

	cout << house.size()<<endl;

	sort(house.begin(), house.end());
	for (int i = 0; i < house.size(); i++)
		cout << house[i] << endl;

	return 0;
}