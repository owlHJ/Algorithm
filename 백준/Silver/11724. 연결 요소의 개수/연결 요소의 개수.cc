#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int>node[1001];
int visited[1001];
queue<int>q;


void BFS() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < node[x].size(); i++) {
			if (!visited[node[x][i]]) {
				int num = node[x][i];
				visited[num] = true;
				q.push(num);
			}
		}

	}

}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		node[a].push_back(b);
		node[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++ ;
			q.push(i);
			visited[i];
			BFS();
		}
	}

	cout << cnt;


	return 0;
}