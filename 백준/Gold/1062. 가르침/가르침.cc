#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool alpha[26];
int word, teach;
int ans;
vector<string>words;
void Set() {
	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;
	for (int i = 0; i < word; i++) {
		string s;
		cin >> s;
		words.push_back(s);
	}
}


void Simulate(int cnt,int idx) {
	
	if (cnt == teach - 5) {
		int count = 0;
		for (int i = 0; i < words.size(); i++) {
			bool read=true;
			for (int j = 4; j < words[i].length()-4; j++) {
				int n = words[i][j] - 'a';
				if (alpha[n])continue;
				else read = false;
			}
			if (read == true)
				count++;
		}
		ans = max(count, ans);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alpha[i] == true)continue;
		alpha[i] = true;
		Simulate(cnt + 1, i);
		alpha[i] = false;
	}


}

int main() {


	cin >> word >> teach;

	if (teach < 5) {//진행할 필요가 없음
		Set();
		cout << 0;

	}
	

	else {
		Set();
		Simulate(0,0);
		cout << ans;
	}

	return 0;
}