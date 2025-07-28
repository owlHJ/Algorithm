#include<vector>
#include<queue>
#include<iostream>
using namespace std;
bool visited[101][101]={false,};
int dx[4] = {0,1,0,-1};
int dy[4] ={1,0,-1,0};
struct qInfo
{
    int x;
    int y;
    int cnt;
};
bool InRange(const int &x, const int &y,const vector<vector<int> > &maps)
{
    return x>=0 && x<maps.size() && y>=0 &&y<maps[0].size(); 
}
bool cango(const qInfo &info, const vector<vector<int> > &maps)
{
    bool bRet = true;
    if(InRange(info.x,info.y,maps) == false) bRet = false; 
    else if(maps[info.x][info.y] == 0) bRet = false;
    else if(visited[info.x][info.y]==true) bRet = false;
    
    return bRet;
}
int BFS(queue<qInfo>q1,const vector<vector<int> > &maps)
{
    int iRet =0;
    bool bFlag = false;
    while(!q1.empty())
    {
        qInfo tempinfo = q1.front();
        q1.pop();
        //cout<<tempinfo.x<<", "<<tempinfo.y<<endl;
        if(tempinfo.x == maps.size() -1 && tempinfo.y == maps[0].size() - 1)
        {
            bFlag = true;
            iRet = tempinfo.cnt;
            break;
        }
        
        for(int i=0;i<4;++i)
        {
            qInfo nextInfo = {tempinfo.x + dx[i], tempinfo.y + dy[i],tempinfo.cnt + 1};
            if(cango(nextInfo,maps))
            {
                visited[nextInfo.x][nextInfo.y] = true;
                q1.push(nextInfo);
            }
        }
    }
    
    return iRet = (bFlag == true) ? iRet : -1;
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    visited[0][0]=true;
    queue<qInfo>q1;
    q1.push({0,0,1});
        
    answer = BFS(q1,maps);
    return answer;
}