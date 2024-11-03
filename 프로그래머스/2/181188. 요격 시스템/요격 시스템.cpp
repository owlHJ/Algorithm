#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(vector<int> a,vector<int> b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}
int solution(vector<vector<int>> targets) {
    sort(targets.begin(),targets.end(),cmp);
    
    int answer = 0, idx = 0;
    
    while (idx < targets.size())
    {
        // end 타격 범위 Update
        int end = targets[idx++][1];
        answer++;
        
        // end 보다 해당 타겟의 s가 작으면 무시
        while (idx < targets.size() && targets[idx][0] < end)
        {   
            if (targets[idx][1] < end) end = targets[idx][1];
            idx++;
        }
    }
    return answer;
}