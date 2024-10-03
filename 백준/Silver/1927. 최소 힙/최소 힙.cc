#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

int main() {


	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int>>pq;

	for (int i = 0; i < n; i++)
	{
		int test;

		scanf("%d", &test);
		if (test == 0)
		{
			if (pq.empty())printf("0\n");
			else
			{
				printf("%d\n", pq.top());
				pq.pop();

			}
		}
		else pq.push(test);


	}



	return 0;
}