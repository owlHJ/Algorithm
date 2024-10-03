#include <iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		
		int cnt = 0;
		for (int i = n; i <= m; i++) {
			cnt++;
			string s = to_string(i);
			for (int j = 0; j < s.length(); j++) {
				sort(s.begin(), s.end());
				if (s[j] == s[j + 1]) {
					cnt--;
					break;
				}
			}
		}

		cout << cnt << endl;;
	}
	return 0;
}