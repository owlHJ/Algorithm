#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<pair<int,int>>vTime;
vector<pair<int,int>>GetIntTime(vector<vector<string>> &book_time)
{
    vector<pair<int,int>>vRet;
    
    for(int i=0;i<book_time.size();++i)
    {
        int iStart = 0 , iEnd = 0;
        int iMin   = 0 , iSec = 0;
        for(int j=0;j<book_time[i].size();++j)
        {
            string sTemp ="";
            for(int m=0;m<book_time[i][j].length();++m)
            {
                sTemp += book_time[i][j][m];
            }
            iMin = (sTemp[0] -'0') * 10 + sTemp[1] - '0';
            iSec = (sTemp[3] -'0') * 10 + sTemp[4] - '0';
            if( j == 0 )     iStart = iMin * 60 + iSec;
            else if (j == 1) iEnd   = iMin * 60 + iSec;
            else cout<<"EEEERRRRPPP"<<endl;
        }
        
        vRet.push_back({iStart,iEnd});
    }
    return vRet;
}
bool cmp(pair<int,int>iTime1, pair<int,int>iTime2)
{
    if(iTime1.first == iTime2.first)
        return iTime1.second < iTime2.second;
    
    return iTime1.first < iTime2.first;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    // 10분간 청소 -> 다음 손님 가능
    // 최소 객실의 수
    vTime = GetIntTime(book_time);
    sort(vTime.begin(),vTime.end(),cmp);
    
    answer++;
    int iEnd = vTime[0].second + 10;
    vector<int>vRoom;
    vRoom.push_back(iEnd);
   // cout<<vTime[0].first<<", "<<vTime[0].second<<endl;
   // cout<<iEnd<<endl;
    
    for(int i=1;i<vTime.size();++i)
    {
       // cout<<"idx: "<<i<<", "<<vTime[i].first<<", "<<vTime[i].second<<endl;
        bool bRoomFlag = false;
        // 들어갈 수있는 방 있는지 확인
        for(int j = 0;j<vRoom.size();++j)
        {
            // 들어갈 방 존재
            if(vRoom[j] <= vTime[i].first)
            {
                //cout<<"종료 시간 : "<<vRoom[j]<<", "<<vTime[i].first<<endl;
                vRoom[j] = vTime[i].second + 10;
                bRoomFlag = true;
                
               // cout<<"!!!!!!!!!!!!!!!!!!"<<endl;
                break;
            }
        }
        // 없다면
        if(bRoomFlag == false)
        {
          //  cout<<"##############"<<endl;
            vRoom.push_back(vTime[i].second + 10);
            answer++;
        }
       
    }
    return answer;
}