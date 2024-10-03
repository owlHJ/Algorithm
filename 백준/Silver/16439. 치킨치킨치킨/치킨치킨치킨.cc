#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

int n, m;


int arr[31][31];
int answer = 0;
int main() {
	cin >> n >> m;


	//치킨 선호도 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				int score = 0;
				for (int u = 0; u < n; u++) {

					int num=max(arr[u][i], arr[u][j]);
					num = max(num, arr[u][k]);
					
					score += num;
					
				}
				if (answer < score)answer = score;
			}
		}

	}
	/*
	//치킨 선호도 sum
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			score[i] += arr[j][i];
		}
	}
	//sorting
	sort(score, score + 30);
	for (int i = 0; i < 31; i++) {
		cout << i + 1 << " : " << score[i]<<endl;
	}
	cout << score[30] + score[29] + score[28];
	*/

	cout << answer;


	return 0;
}
