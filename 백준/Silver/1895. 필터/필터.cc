#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[40][40];

int t;
int answer = 0;
void Finding(int x, int y) {
	vector<int> v1;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			
			v1.push_back(arr[i][j]);
		}
	}

	sort(v1.begin(), v1.end());
	if (v1[4] >= t) answer++;
}


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	cin >> t;

	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-2; j++) {
			Finding(i, j);
		}
	}
	cout << answer;

	return 0;
}