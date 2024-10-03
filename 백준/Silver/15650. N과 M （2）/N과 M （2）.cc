#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, m;
bool visited[9]={0,};
vector<int>v;

void dfs(int num,int cnt) {
	if (cnt ==m) {
		for (int i = 0; i < m;i++)
			cout << v[i] << " ";
		cout << endl;
		return;
	}
		for (int i = num; i <= n; i++) {//num~ n까지
			if (!visited[i]) {// not visited
				visited[i] = true;//방문처리
				v.push_back(i);
				dfs(i + 1, cnt + 1);
				visited[i] = false;
				v.pop_back();
			}
		}
		
	
}

int main() {

	
	cin >> n >> m;
	dfs(1, 0);


	return 0;
}