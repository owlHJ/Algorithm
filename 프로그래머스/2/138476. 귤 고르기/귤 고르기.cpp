#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#define MAX 10000001
using namespace std;
vector<int>vIdx;
bool visited[100001];
int arr[100001]={0,};
int Answer =INT_MAX;
/*void Back(int cntNow, const int idx, vector<int> &tangerine, const int maxCnt)
{
    if (cntNow == maxCnt)
    {
        int cnt = 0 ;
        for (int i = 0; i < cntNow; ++i)
        {
           // cout << vIdx[i] << " ";
            if(arr[vIdx[i]] == 0 )cnt++;
            arr[vIdx[i]]++;
        }
       // cout<<" 개수: "<<cnt;
       // cout << endl;
        Answer = min(Answer,cnt);
        
         for (int i = 0; i < cntNow; ++i)
        {
            arr[vIdx[i]]--;
        }
        
        return;
    }
    for (int i = idx; i < tangerine.size(); ++i)
    {
        if (visited[i]) continue;

        visited[i] = true;
        vIdx.push_back(tangerine[i]);
        Back(cntNow + 1, i + 1, tangerine, maxCnt);
        vIdx.pop_back();
        visited[i] = false;
    }
}
*/
bool cmp(int v1, int v2)
{
    return v1 > v2;
}
int solution(int k, vector<int> tangerine) {
    int answer  = 0;
   // Back(0,0,tangerine,k);
    sort(tangerine.begin(),tangerine.end(),cmp);
   
    
    vector<int> kind(MAX); 

    for (int i=0;i<tangerine.size();++i)   kind[tangerine[i]]++;
    sort(kind.begin(),kind.end(),cmp);
    
    int iNow    = kind[0];
    int iCnt    = 1;
    int iIdx    = 0;
    for(int i=0;i<k;++i)
    {
        //cout<<kind[iIdx]<<" ";
        
        if(kind[iIdx] == 0)
        {
            iNow = kind[++iIdx];
            ++iCnt;
        }
        kind[iIdx]--;
    }
    
    answer = iCnt;
    return answer;
}