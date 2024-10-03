#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool visited[9];
int N, M;
vector<int>v;
vector<int>answer;
void Back(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << '\n';
		return;
	}
	int tmp = -1;
	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && tmp != v[i]&&answer.size()==0) {
			tmp = v[i];
			answer.push_back(v[i]);
			visited[i] = true;
			Back(cnt + 1);
			answer.pop_back();
			visited[i] = false;
		}
		else if (!visited[i] && tmp != v[i]&&answer[answer.size()-1]<=v[i])
		{
			tmp = v[i];
			answer.push_back(v[i]);
			visited[i] = true;
			Back(cnt + 1);
			answer.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end()); // 오름차순 정렬

	Back(0);
}