#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int>board[1000001];
bool visited[1000001];
int check(const int nodeNxt,const int childNum, int state)
{
    //다음 노드, 다음 노드 자식 개수, 현재 state
    // -1 error, 1, 홀짝, 2 역홀짝
    int iRet =-1;
    //짝짝, 홀홀
    if(nodeNxt%2 == childNum%2)
    {
        if(state==2)  return -1;//iRet = -1;
        return 1;
        //else iRet = 1;
    }
    // 홀짝 or 짝Q홀
    else if(nodeNxt%2 != childNum%2) 
    {
        //state가 홀홀, 짝짝
        if(state==1) return -1;// iRet = -1;
        return 2;
        //else iRet = 2;
    }
    
    return iRet;
}
int bfs(const int root)
{
    queue<int>q1;
    q1.push(root);
    int checkNode = 0;
    checkNode = check(root, board[root].size(), checkNode);
    
    while(!q1.empty())
    {
        int now = q1.front();
        q1.pop();
        
        for(int i=0;i<board[now].size();++i)
        {
            int nodeNxt = board[now][i];
            if(!visited[nodeNxt])
            {
                visited[nodeNxt]=true;
                q1.push(nodeNxt);
                
                //다음 노드, 다음 노드 자식 개수, 현재 state
                checkNode = check(nodeNxt, board[nodeNxt].size()-1, checkNode);
                if(checkNode == -1)
                    return -1;
            }
        }
    }
    
    return checkNode;
}
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    //홀,짝 -> node = 홀 -> 자식 -> 홀
    
    //역 -> node = 홀 -> 자식 ->짝 
    
    for(int i=0;i<edges.size();++i)
    {
        int arr[2] ={0,};
        for(int j=0;j<2;++j)
        {
            arr[j]=edges[i][j];
        }
        board[arr[0]].push_back(arr[1]);
        board[arr[1]].push_back(arr[0]);
    }
    
    for(int i=0;i<nodes.size();++i)
    {
        int root = nodes[i];
        visited[root]=true;
        int idx = bfs(root);
        //cout<<i+1<<"번째: "<<idx<<endl;
        //cout<<"루트: "<<root<<endl;
        //1,2
        if(idx != -1) answer[idx-1]++;
        fill(visited, visited+1000001, false);
    }
    
    return answer;
}