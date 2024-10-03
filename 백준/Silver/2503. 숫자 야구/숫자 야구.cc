#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

bool n[1000]={true,};
void Set() {
	for (int i = 123; i < 1000; i++) {
		n[i] = true;
	}
	for (int i = 123; i < 1000; i++) {
		string s = to_string(i);
		if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2])n[i] = false;//서로 다른 숫자
		if (s[0] - '0' == 0 || s[1] - '0' == 0 || s[2] - '0' == 0)n[i] = false;//1~9이므로
	}
}


void Simulate(int num,int s, int b) {
	string test = to_string(num);
	
	for (int i = 123; i < 1000; i++) {
		int strike = 0, ball = 0;
		if (n[i] == true) {
			string temp = to_string(i);
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (j == k && test[j] == temp[k])strike++;
					if (j != k && test[j] == temp[k])ball++;
				}
			}
			if (strike != s || ball != b) n[i] = false;
		}
	}
}

int main() {
	int T;
	cin >> T;
	int num=0;

	Set();
	for (int i = 0; i < T; i++) {
		int s, b;
		cin >> num>>s>>b;
		Simulate(num,s, b);
	}
	int ans = 0;

	for (int i = 123; i < 1000; i++)
		if (n[i] == true)ans++;
	cout << ans;


	return 0;
}