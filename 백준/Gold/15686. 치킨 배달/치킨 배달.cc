#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // Include for std::min
using namespace std;

struct Pos {
	int x;
	int y;
};

int n, m;
int board[51][51];
int answer = 99999;
bool visited[14] = { false, };
vector<Pos> vChicken;
vector<Pos> vHome;

bool InRange(const int x, const int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int ValDistChicken() {
	int iRet = 0;

	for (int i = 0; i < vHome.size(); ++i) {
		int temp = 99999;
		for (int j = 0; j < vChicken.size(); ++j) {
			if (!visited[j]) continue;
			temp = min(temp, abs(vHome[i].x - vChicken[j].x) + abs(vHome[i].y - vChicken[j].y));
		}
		iRet += temp;
	}

	return iRet;
}

void BackTracking(const int start, const int cnt, const int counter) {
	if (cnt == counter) {
		answer = min(answer, ValDistChicken());
		return;
	}

	for (int i = start; i < vChicken.size(); ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		BackTracking(i + 1, cnt + 1, counter); // Ensure moving to the next index
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) vHome.push_back({ i, j });
			if (board[i][j] == 2) vChicken.push_back({ i, j });
		}
	}

	// Try all possible numbers of open chicken stores from 1 to m
	for (int i = 1; i <= m; ++i) {
		BackTracking(0, 0, i);
	}

	cout << answer;

	return 0;
}