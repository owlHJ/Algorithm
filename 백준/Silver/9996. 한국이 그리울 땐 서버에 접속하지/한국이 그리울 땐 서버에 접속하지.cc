#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string test;
	cin >> test;
	string left="", right="";
	bool flag = false;
	for (int i = 0; i < test.length(); i++) {
		if (test[i] != '*' && flag == false) {
			left += test[i];
		}
		else if (flag == true)
			right += test[i];

		if (test[i] == '*')flag = true;
	}

	//cout << left << " " << right << endl;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (left.length() + right.length() > s.length())cout << "NE" << endl;
		else {

			bool answer_flag = true;
			for (int j = 0; j < left.length(); j++) {
				if (s[j] != left[j]) answer_flag = false;
				//	cout << s[j];
			}
			//cout << " ";
			for (int j = 0; j < right.length(); j++) {
				if (s[s.length() - right.length() + j] != right[j])answer_flag = false;
				//cout << s[s.length()  - right.length() + j];
			}
			//cout << endl;

			if (answer_flag == true)
				cout << "DA" << endl;
			else
				cout << "NE" << endl;

		}
	}

	return 0;
}