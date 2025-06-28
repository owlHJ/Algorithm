#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>v1, vector<int>v2)
{
    if(v1[0] == v2[0])
        return v1[1] > v2[1];
    return v1[0]>v2[0];
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int x= 0,y = 0;
  
        
    for(int i=0;i<sizes.size();++i)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            x = (sizes[i][0] > x) ? sizes[i][0] : x;
            y = (sizes[i][1] > y) ? sizes[i][1] : y;    
        }
        else
        {
            x = (sizes[i][1] > x) ? sizes[i][1] : x;
            y = (sizes[i][0] > y) ? sizes[i][0] : y;    
        }
        
    }
    answer = x * y;
    return answer;
}