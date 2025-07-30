#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    answer.push_back(arr[0]);
    for(int i=1;i<arr.size();++i)
    {
        bool bFlag = true;
        if(arr[i] != answer[answer.size()-1])
        {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}