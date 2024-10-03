#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<tuple>
using namespace std;

int main() {

	while (true) {
		string s;
		getline(cin, s);
		if (s == ".")return 0; //종료 signal
		stack<char>st1;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') st1.push(s[i]);
			else if (s[i] == ')') {
				if (!st1.empty() && st1.top() == '(')st1.pop();
				else {
					cout << "no" << endl;
					break;
				}
			}
			else if (s[i] == ']') {
				if (!st1.empty() && st1.top() == '[')st1.pop();
				else { 
					cout << "no" << endl; 
					break;
				}
			}
			if (i == s.length() - 2 && !st1.empty()) 
				cout << "no" << endl;
			else if (i == s.length() - 2)
				cout << "yes" << endl;
		}


	}

	return 0;
}