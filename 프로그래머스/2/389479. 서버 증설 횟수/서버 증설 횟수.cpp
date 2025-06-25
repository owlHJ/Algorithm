#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int user_limit = m;
    int server_time = k;
    int server[25]={0,};
    cout<<players.size();
    for(int i=0;i<players.size();++i)
    {
        if(players[i] >= user_limit + server[i] * user_limit)
        {
            int serverNum = (players[i] - server[i]*user_limit) / (user_limit);
            answer+=serverNum;
            for(int j=0;j<server_time;++j)
            {
                
                if(i+j <= players.size() -1 )server[i+j] += serverNum;
            }
        }
    }
    return answer;
}