#include <string>
#include <vector>

using namespace std;
int dist[3]={2,3,4};
bool CanBalance (const int &w1, const int &w2)
{
    bool bRet = false;

    
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(dist[i] * w1 == dist[j] * w2) 
            {
                bRet = true;
                return bRet;
            }
        }
    }
    
    return bRet;
}
long long solution(vector<int> weights) {
    long long answer = 0;
    // 2, 3, 4 m 에 좌석이 있음
    // 토크 = m * s 임
    vector<long long> cnt(1001,0);
    for(int i=0; i<weights.size(); i++)
        cnt[weights[i]]++;
    
    for(int i=0; i<weights.size(); i++)
    {
        //2:3
        if(weights[i]%2==0)
        {
            long long base = (weights[i]/2) * 3;
            if(base <= 1000) answer+=cnt[base];
        }
        //3:4
        if(weights[i]%3==0)
        {
            long long base = (weights[i]/3) * 4;
            if(base <= 1000) answer+=cnt[base];
        }
        
        //1:2
        long long base = weights[i] * 2;
        if(base <= 1000) answer+=cnt[base];
    }
    
    for(int i=100; i<=1000; i++)
    {
        if(cnt[i] >= 2)
            answer += (long long)(cnt[i] * (cnt[i]-1))/2;
    }
    
    return answer;
}