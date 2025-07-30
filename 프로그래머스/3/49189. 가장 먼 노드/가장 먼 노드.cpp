#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
//int BFS(queue<pair<int,int>> &q1,const vector<int> &v1[200000])
int arrcnt[20001] = {0,};
void BFS(queue<pair<int,int>> &q1, const vector<int> v1[200000])
{
    int iRet = 0;
    bool visited[200001]={false,};
    visited[0] = true;
    
    while(!q1.empty())
    {
        pair<int,int> infotemp = q1.front();
        q1.pop();
        arrcnt[infotemp.first] = max(arrcnt[infotemp.first], infotemp.second);
        //cout<<infotemp.first<<", cnt: "<<infotemp.second<<endl;
        for(int i=0;i<v1[infotemp.first].size();++i)
        {
            if(visited[v1[infotemp.first][i]] == true) continue;
            visited[v1[infotemp.first][i]] = true;
            q1.push({v1[infotemp.first][i], infotemp.second + 1});
        }
    }
    
    return ; //iRet;
}
bool cmp(int a, int b)
{
    return a>b;
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int>v1[200000];
    for(int i=0;i<edge.size();++i)
    {
        int a,b;
        a=edge[i][0];
        b=edge[i][1];
        
        v1[a-1].push_back(b-1);
        v1[b-1].push_back(a-1);
    }
    queue<pair<int,int>>q1;
    
    q1.push({0,1});
    BFS(q1,v1);
    sort(arrcnt + 0, arrcnt + 20000, cmp);
    int num = arrcnt[0];
    for(int i=0;i<20000;++i)
    {
        if(arrcnt[0] != arrcnt[i]) break;
          answer++;
     }
    //if(v1[0].size()==1) answer = 1;
    
    return answer;
}