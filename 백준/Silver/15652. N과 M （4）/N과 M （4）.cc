#include<iostream>
#include<vector>
using namespace std;
int num;
int num_cnt;
vector<int>v;
bool visited[10];
void Back(int cnt) {
	if (cnt == num_cnt) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= num; i++) {
		
			if (v.size() == 0) {
				v.push_back(i);
				Back(cnt + 1);
				v.pop_back();
			}
			else if (v[v.size() - 1] <= i) {
				v.push_back(i);
					//visited[i] = true;
				Back(cnt + 1);
					//visited[i] = false;
				v.pop_back();
			}
				
			
		}
	}

}

int main() {

	
	cin>>num >> num_cnt;

	Back(0);


	return 0;
}