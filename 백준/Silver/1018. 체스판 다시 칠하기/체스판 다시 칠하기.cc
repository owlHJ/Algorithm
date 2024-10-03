#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
int ans = INT_MAX;
int n, m;

string mw[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};
string mb[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};
char test[50][50];
bool CanGo(int x,int y) {
	return x + 7 < n && y + 7 < m;
}
void Count(int x, int y) {
	int cnt_b = 0,cnt_w=0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (test[x + i][y + j] != mw[i][j]) {
				cnt_w++;
			}
				
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (test[x + i][y + j] != mb[i][j]) {
				cnt_b++;
			}
				
		}
	}
	int temp = min(cnt_b, cnt_w);
	if (ans > temp)
		ans = temp;
}
int main() {
	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> test[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (CanGo(i, j)) {
				Count(i, j);
			}
		}
	}
	cout << ans;


	return 0;
}