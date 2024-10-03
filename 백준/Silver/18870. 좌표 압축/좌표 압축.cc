#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int>pos;
vector<int>temp;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int n;
		cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pos.push_back(a);
	}
	vector<int> temp(pos);

	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());



	for (int i = 0; i < n; i++)
	{
		//외우자 
		// i번째 요소값의 위치 it
		auto it = lower_bound(temp.begin(), temp.end(), pos[i]);
		// it에서 cv벡터의 시작 주소값을 빼준 값이 답
		cout << it - temp.begin() << ' ';
	}





	
	return 0;
}