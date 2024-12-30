#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 10007

long long dp[1001][10]={0,};

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<10;++i)
    {
        dp[0][i] = 1;
    }
    for(int i=0;i<1001;++i)
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<1001;++i)
    {
        for(int j=1;j<10;j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
            dp[i][j] %=MOD;
        }
    }

    long long iSum = 0;
    for(int i=0;i<10;++i)
    {
        iSum+= dp[n-1][i] ;
    }
    cout<<iSum% 10007;
    return 0;
}