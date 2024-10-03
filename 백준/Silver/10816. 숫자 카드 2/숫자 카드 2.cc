#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);




	int n;
	int k;
	cin >> n;
	vector<int>v1(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];

	}
	sort(v1.begin(), v1.end());

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		auto upper = upper_bound(v1.begin(), v1.end(), k);
		auto lower = lower_bound(v1.begin(), v1.end(), k);
		cout <<upper-lower<<" ";
	}
	
	return 0;
}
