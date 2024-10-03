#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int>people;
bool visited[100010];
queue<pair<int,int>>q;

int a,b;
int answer;

void BFS() {
	while (!q.empty()) {
		pair<int,int> curr_num = q.front();
		int x = curr_num.first, cost = curr_num.second;
		q.pop();
		if (x == b) {
			answer = cost;
			break;
		}


		int x1 = x -1;
		int x2= x + 1;
		int x3 = x * 2;
		if (x1 >= 0 && !visited[x1]) {
			visited[x1] = true;
			q.push(make_pair(x1, cost + 1));
		}

		if (x2 <= b && !visited[x2]) {
			visited[x2] = true;
			q.push(make_pair(x2,cost+1));
		}


		if (x3 <= b+1 && !visited[x3]) {
			visited[x3] = true;
			q.push(make_pair(x3,cost+1));
		}
	}

}

int main() {
	cin >> a >> b;

	q.push(make_pair(a,0));
	visited[a] = true;

	BFS();


	cout << answer;
	return 0;
}