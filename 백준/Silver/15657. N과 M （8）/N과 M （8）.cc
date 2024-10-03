#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num;
int num_cnt;
vector<int>v;
vector<int>n;

bool visited[10];
void Back(int cnt,int start) {
	if (cnt == num_cnt) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = start; i < n.size(); i++) {
			v.push_back(n[i]);
			Back(cnt+ 1, i);
			v.pop_back();
		}
	}
}

int main() {


	cin >> num >> num_cnt;
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		n.push_back(a);
	}
	sort(n.begin(), n.end());


	Back(0,0);


	return 0;
}