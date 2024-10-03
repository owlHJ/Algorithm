#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

int people, n, T;


int main() {
	cin >> people >> n >> T;
	int cnt[2] = { 0,0 };
	int count = 0;
	int cnt_game = 2;
	while (true) {


		for (int i = 0; i < 4; i++) {//기본
			cnt[i % 2]++;
			if (cnt[T] == n) {
				cout << count;
				return 0;
			}
			count = (count + 1) % people;
			//cout << count;
		}
		//곱셈 부르기
		for (int i = 0; i < 2; i++) {//기본
			for (int j = 0; j < cnt_game; j++) {
				cnt[i]++;
				if (cnt[T] == n) {
					cout << count;
					return 0;
				}
				count = (count + 1) % people;

				//cout << count;
			}
		}
		cnt_game++;
	}

	cout << cnt;
	cout << T;
	return 0;
}
