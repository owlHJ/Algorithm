#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int &a, int &b)
{
    return a<=b;
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int idx=0;idx<commands.size();++idx)
    {
        int i = commands[idx][0] - 1;
        int j = commands[idx][1] - 1;
        int k = commands[idx][2] - 1;
        vector<int> v1;
        
        for(int n=i;n<=j;++n)
            v1.push_back(array[n]);
        sort(v1.begin(),v1.end(),cmp);
        answer.push_back(v1[k]);
    }
    return answer;
}