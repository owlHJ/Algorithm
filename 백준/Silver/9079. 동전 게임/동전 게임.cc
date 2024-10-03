#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
using namespace std;

int T;


bool arr[3][3];
bool visited[512];
int answer = 0;
queue<pair<int, int>>q;
void ChangeCol(int col) {
	for (int i = 0; i < 3; i++) {
		arr[i][col] = !arr[i][col];
	}
}
void ChangeRow(int row) {
	for (int i = 0; i < 3; i++) {
		arr[row][i] = !arr[row][i];
	}
}
void ChangeCross(bool dir) {
	if (dir) {//순방향
		for (int i = 0; i < 3; i++) {
			arr[i][i] = !arr[i][i];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			arr[2-i][i] = !arr[2-i][i];
		}
	}
}

void Set() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			char c;
			cin >> c;
			if (c == 'H') {

				arr[i][j]=0;
			}
			else {
				arr[i][j] = 1;
			}
		}
	for (int i = 0; i < 512; i++)visited[i] = false;
	while (!q.empty())q.pop();
}

void Show() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int ArraytoInt() {
	int decimal = 0;
	int power = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j]) {
				decimal += (1 << power);
			}
			power++;
		}
	}

	return decimal;
}
void InttoArray(int decimal) {
	for (int i = 2; i >= 0; i--) {
		for (int j = 2; j >= 0; j--) {
			arr[i][j] = (decimal & (1 << (i * 3 + j))) != 0;
		}
	}
}
bool IsCorrect() {
	bool temp = arr[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (temp != arr[i][j]) return false;
		}
	}
	return true;

	
	
}
int Simulate() {
	
	int w = ArraytoInt();
	q.push(make_pair(w,0));
	visited[w] = true;

	while (!q.empty()) {
		int curr = q.front().first;
		int count = q.front().second;
		q.pop();
		InttoArray(curr);
	//	cout << " cnt : " << count << endl;
	//	Show();

		if (IsCorrect()) {
			//cout << count;
			return count;
		}


		//cout << "@" << endl;
		int next_count = count + 1;
		//Col
		for (int i = 0; i < 3; i++) {

			ChangeCol(i);
			int next = ArraytoInt();
			if (!visited[next]) {
				visited[next] = true;
				q.push(make_pair(next, next_count));
			}
			ChangeCol(i);
		}
		//Row
		for (int i = 0; i < 3; i++) {

			ChangeRow(i);
			int next = ArraytoInt();
			if (!visited[next]) {
				visited[next] = true;
				q.push(make_pair(next, next_count));
			}


			ChangeRow(i);
		}
		//Cross
		for (int i = 0; i < 3; i++) {

			ChangeCross(i);
			int next = ArraytoInt();
			if (!visited[next]) {
				visited[next] = true;
				q.push(make_pair(next, next_count));
			}
			ChangeCross(i);
		}

	

	}

	return -1;
	

}
int main() {
	cin >> T;
	


	for (int i = 0; i < T; i++) {
		Set();
		
	//	cout << i + 1 << "  번째 시작" << endl;
	//	Show();
	//	cout << endl;
		int num = Simulate();
	//	cout << endl;
		cout << num << endl;
	}
	return 0;
}
