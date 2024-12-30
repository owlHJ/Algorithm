#include<iostream>

using namespace std;

int dp[1001];
int main()
{
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 3;
    int n;
    cin>>n;

    for(int i=3;i<n;++i)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout<<dp[n-1];

    return 0;
}