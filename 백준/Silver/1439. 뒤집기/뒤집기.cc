#include<iostream>
#include<string>
using namespace std;

int main() {

	string s;
	cin >> s;
	int count = 0;
	int test = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (test != s[i]) {//001100일때 1이라면
			if (s[i - 1] != s[i])//그리고 전이랑 다르다면 
				count++;
		}
	}

	cout << count;

	return 0;
}