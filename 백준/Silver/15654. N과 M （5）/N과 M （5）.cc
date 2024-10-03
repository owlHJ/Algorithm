#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num_cnt,num;
vector<int>v;
vector<int>n;
bool visited[10];
void Back(int cnt) {
	if (cnt == num_cnt) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < n.size(); i++) {
			if (visited[i]==false) {
				v.push_back(n[i]);
				visited[i] = true;
				Back(cnt + 1);
				visited[i] = false;
				v.pop_back();
			}
				
			
		}
	}

}

int main() {

	
	cin>>num >> num_cnt;
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		n.push_back(a);
	}
	sort(n.begin(), n.end());

	Back(0);


	return 0;
}