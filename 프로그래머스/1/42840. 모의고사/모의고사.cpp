#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(pair<int,int> left, pair<int,int> right)
{
    if(left.first == right.first)
        return left.second <right.second;
    else
        return left.first > right.first;
}
void Simulate(vector <pair<int,int>> &v1,const vector<int> &answers)
{
     int arr1[5]={1,2,3,4,5};
    int arr2[8]={ 2, 1, 2, 3, 2, 4, 2, 5};
    int arr3[10]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int limitsIdx[3]={5,8,10};
    int cnt = 0;

    for(int i=0;i<answers.size();++i)
    {
        int idx = i % limitsIdx[0];
        if(arr1[idx] == answers[i])cnt++;    
    }
    v1.push_back({cnt,1});
    
     cnt =0;  
    for(int i=0;i<answers.size();++i)
    {
        int idx = i %limitsIdx[1];
        if(arr2[idx] == answers[i])cnt++;    
    }
    v1.push_back({cnt,2});
    
     cnt =0;
    for(int i=0;i<answers.size();++i)
    {
        int idx = i %limitsIdx[2];
        if(arr3[idx] == answers[i])cnt++;    
    }
    v1.push_back({cnt,3});
    
    sort(v1.begin(),v1.end(),cmp);
    
    return;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
   
    vector<pair<int,int>> v1;
    Simulate(v1,answers);
    
    answer.push_back(v1[0].second);
    for(int i=1;i<v1.size();++i)
    {
        if(v1[0].first == v1[i].first)
        {
            answer.push_back(v1[i].second);
        }
    }
    
    return answer;
}