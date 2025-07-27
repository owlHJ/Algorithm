#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[201] ={false,};
void BFS(queue<int> &q1, const int &limit, const vector<vector<int>> &computers)
{
    while(!q1.empty())
    {
        int iTemp = q1.front();
        q1.pop();
        
        for(int i=0;i<limit;++i)
        {
            if(computers[iTemp][i] == 0 || visited[i] == true) continue;
            visited[i] = true;
            q1.push(i);
        }
    }
    
    return;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size();++i)
    {
        queue<int>q1;
        if(visited[i] == true) continue;
        answer++;
        for(int j=0;j<n;++j)
        {
            if(computers[i][j] == 1 && visited[j] != true)
            {
                visited[j] = true;
                q1.push(j);
            }
            BFS(q1,n,computers);
        }
    }
    
    return answer;
}