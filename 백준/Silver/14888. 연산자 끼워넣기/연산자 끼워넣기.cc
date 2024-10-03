#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;
int max_num = INT_MIN;
int min_num = INT_MAX;
int n;
int arr[4] = { 0, };

vector<int>v;
vector<int>v2;

void  Simulate(int cnt) {
	if (cnt > n - 1) {
		int sum_n=v[0];
		
		
		
		for (int i = 0; i < n-1; i++) {
			if (v2[i] == 0) sum_n += v[i+1];
			else if (v2[i] == 1)sum_n -= v[i+1];
			else if (v2[i] == 2)sum_n *= v[i+1];
			else sum_n /= v[i+1];
		}


		if (max_num < sum_n)
			max_num = sum_n;
		if (min_num > sum_n)
			min_num = sum_n;
			return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (arr[i] != 0) {
				arr[i]--;
				//계산
				v2.push_back(i);		
				Simulate(cnt + 1);
				v2.pop_back();
				arr[i]++;
			}

		}
	}
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < 4; i++)
		cin >> arr[i];

	Simulate(1);
	cout << max_num<<endl<<min_num;


	return 0;
}