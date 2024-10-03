#include<iostream>
#include<stack>

using namespace std;

int main() {

	/*\
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을
			
	*/

	int n;
	cin >> n;
	stack<int>st;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int a;
			cin >> a;
			st.push(a);
		}
		else if (s == "pop") {
			if (st.empty())cout << -1 << endl;
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (s == "size") cout << st.size() << endl;
		else if (s == "empty")cout << st.empty() << endl;
		else {
			if (st.empty())cout << "-1" << endl;
			else
				cout << st.top() << endl;

		}
	}
	return 0;
}