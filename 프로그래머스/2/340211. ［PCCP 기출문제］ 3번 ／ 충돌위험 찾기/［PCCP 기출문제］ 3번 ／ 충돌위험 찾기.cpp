/*#include <string>
#include <vector>
#include <iostream>
using namespace std;
//우선순위 : r 좌표 > c좌표
//도착하면 로봇 삭제
//로봇이 벗어나는 경로 X

// 충돌나는 경우 reusult
struct Pos {
    int x;
    int y;
};

struct Info {
    Pos  posNow;   // 현재 좌표
    Pos  posEnd;   // 목표 좌표
    bool bEnd;     // 도착 여부
    bool bEnable;
    vecotr
};

vector<Info>vRoutes;
int m,n;
void Show(const vector<Info> &vHorse)
{
    cout<<"###########################"<<endl;
    for(int i=0;i<vHorse.size();++i)
    {
        cout<<"Now: "<<vHorse[i].posNow.x<<", "<<vHorse[i].posNow.y<<endl;
        cout<<"End: "<<vHorse[i].posEnd.x<<", "<<vHorse[i].posEnd.y<<endl;
    }
    
    cout<<"###########################"<<endl;
}
bool CanGo(const int &x, const int &y)
{
    return x>=1 && x<=m && y >= 1 && y <= n;
}
bool CheckGame(const vector<Info> &vGame)
{
    bool bRet = true;
    
    for(int i=0;i<vGame.size();++i)
    {
        if (vGame[i].bEnable == true)
        {
            bRet =false;
            break;
        }
        
        if((vGame[i].posNow.x != vGame[i].posEnd.x) ||
            vGame[i].posNow.y != vGame[i].posEnd.y)
        {
            bRet =false;
            break;
        }
        
    }
    
    return bRet;
}
void Move(vector<Info> &vHorse)
{
    for(int i=0;i<vHorse.size();++i)
    {
        int xNow = vHorse[i].posNow.x;
        int yNow = vHorse[i].posNow.y;
        //1. R이 우선 -> x 좌표
        if(vHorse[i].posNow.x != vHorse[i].posEnd.x)
        {
            vHorse[i].posNow.x = (xNow > vHorse[i].posEnd.x) ? xNow - 1 : xNow + 1;
        }
        else if (vHorse[i].posNow.y != vHorse[i].posEnd.y)
        {
            vHorse[i].posNow.y = (yNow > vHorse[i].posEnd.y) ? yNow - 1 : yNow + 1;            
        }
        else continue;
    }
    
    return;
}
int CountDup(vector<Info> &v1)
{
    struct InfoDup
    {
        int x;
        int y;
        int cnt;
    };
    
    int iRet = 0;
    int arr[101][101] = {0,};
    vector<InfoDup>vCheck;
    for(int i=0;i<v1.size();++i)
    {
        //arr[v1[i].posNow[i].x][v1[i].posNow[i].y]++;
        if(v1[i].bEnable==false) continue;
        int x = v1[i].posNow.x;
        int y = v1[i].posNow.y;
        int cnt = 1;
        if(vCheck.empty()) vCheck.push_back({x,y,cnt});
        else
        {
            bool bFlag = false;
            for(int j=0;j<vCheck.size();++j)
            {
                if(vCheck[j].x == x && vCheck[j].y == y)
                {
                    bFlag = true;
                    vCheck[j].cnt++;
                    break;
                }
            }
            if(bFlag == false) vCheck.push_back({x,y,1});
        }
    }
    for(int i=0;i<vCheck.size();++i)
    {
        if(vCheck[i].cnt > 1) iRet++;
    }
    if(iRet >= 1)
    {
       // cout<<"중복 개수: "<<iRet<<endl;
       // Show(v1);
    }
    return iRet;
}
//void ExchangeBoard(vector<vector<int>> points)
void HorseSet(vector<Info> &v1)
{
    for(int i=0;i<v1.size();++i)
    {
        if((v1[i].posNow.x == v1[i].posEnd.x) &&
            v1[i].posNow.y == v1[i].posEnd.y)
        {
            v1[i].bEnable = false;
        }
    }
    
    return;
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    //Setup
    vector<Info> vHorse;
    for(int i=0;i<routes.size();++i)
    {
        Info infoTemp;
        infoTemp.posNow.x = points[routes[i][0] - 1][0];
        infoTemp.posNow.y = points[routes[i][0]- 1][1];
        infoTemp.posEnd.x = points[routes[i][1]- 1][0];
        infoTemp.posEnd.y = points[routes[i][1]- 1][1];
        infoTemp.bEnd   =false;
        infoTemp.bEnable = true;
        vHorse.push_back(infoTemp);
    }
    m = points.size();
    n = points[0].size();
    
    //Simultion
    bool bGameFlag = false;
    int cnt =0;
    //시작 중복 Count
    answer += CountDup(vHorse);

    while(bGameFlag == false)
   {
        //cnt ++;
        //if( cnt >= 10) break;
        //1.게임 완료 처리
        bGameFlag = CheckGame(vHorse);
        if(bGameFlag == true)
        {
            break;
        }
        //2.Move
        Move(vHorse);
        //3.충돌 확인
        answer += CountDup(vHorse);
        //4.죽음 표시
        HorseSet(vHorse);
        //Show(vHorse);
        
   }
    
    return answer;
}
*/    
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
// 포인트의 좌표
unordered_map<int,pair<int,int>> pos;
// 로봇의 시간대 별 누적 경로
vector<map<pair<int,int>,int>> path_count;
int answer;

void movePath(vector<int>&r){
    pair<int,int> final;
    int time=0;
    // r은 {1,2,3,4} 처럼 이동할 포인트에 대한 경로로 나와있으니 1->2, 2->3, 3->4 순서로 이동한다.
    for(int i=0;i<r.size()-1;i++){
        // 현재 좌표
        pair<int,int>s=pos[r[i]];
        // 다음 좌표
        pair<int,int>e=pos[r[i+1]];
        final=e;
        
        while(s!=e){
            // 현재 시간에 s라는 좌표에 로봇이 1개 이동했다는 의미
            path_count[time][s]++;
            if(path_count[time][s]==2)answer++;
            int dy=s.first-e.first;
            int dx=s.second-e.second;
            
            if(dy!=0){
                if(dy>0)s.first--;
                else s.first++;
            }
            else if(dx!=0){
                if(dx>0)s.second--;
                else s.second++;
            }
            time++;
        }
    }
    // 도착
    path_count[time][final]++;
    if(path_count[time][final]==2)answer++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    
    for(int i=0;i<points.size();i++){
        // 각 포인트에 대한 좌표 저장
        pos[i+1]={points[i][0],points[i][1]};
    }
    path_count.resize(100001);
    
    for(auto p:routes){
        movePath(p);
    }
    
    return answer;
}