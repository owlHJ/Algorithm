#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
char arr[51][51];
int x,y;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool InRange(const int posX, const int posY)
{
    return posX >=0 && posX < x && posY <y && posY >= 0;
}
void Crain(char (&arr)[51][51], string &sCmd)
{
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<y;++j)
        {
            if(arr[i][j] == sCmd[0])
            {
                 arr[i][j]= '~';
            }
        }
    }
}
void Show(char (&arr)[51][51])
{
      for(int i=0;i<x;++i)
    {
        for(int j=0;j<y; ++j)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
        cout<<endl;
}
void forkLift(char (&arr)[51][51], string &sCmd)
{
    char cTemp[51][51]={};
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<y; ++j)
        {
            cTemp[i][j] = arr[i][j];
        }
    }
    
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<y;++j)
        {
            if(arr[i][j] == sCmd[0])
            {
                for(int m=0;m<4;++m)
                {
                    int nx = i+dx[m];
                    int ny = j+dy[m];
                    
                    if(InRange(nx,ny) == false)
                    {
                        cTemp[i][j]= '~';
                    }

                    else if(InRange(nx,ny) == true && arr[nx][ny] == '~')
                    {
                        //cTemp[i][j]= '~';
                        //cout<<"시작: "<<i<<", "<<j<<endl;
                        
                        queue<pair<int,int>>q1;
                        bool bTemp[51][51]={false,};
                        bool bFlag = false;
                        q1.push({nx,ny});
                        bTemp[nx][ny]=true;
                        //cout<<"이동: "<<nx<<", "<<ny<<endl;
                        while(!q1.empty())
                        {
                            int cx = q1.front().first ,cy= q1.front().second;
                            q1.pop();
                            //cout<<"이동: "<<cx<<", "<<cy<<endl;
                            // 매우 중요하다. 가장자리 Tip
                            if( cx==0 || cx==x-1 || cy==0 || cy==y-1)
                            {
                               // cout<<"종료: "<<cx<<", "<<cy<<endl;
                                cTemp[i][j]= '~';
                                break;
                            }
                            
                            for(int n=0;n<4;++n)
                            {
                                int nx = cx+dx[n];
                                int ny = cy+dy[n];
                                
                                if(InRange(nx,ny) == true && arr[nx][ny] == '~' && !bTemp[nx][ny])
                                {
                                    bTemp[nx][ny]=true;
                                    q1.push({nx,ny});
                                   // cout<<"저장: "<<nx<<", "<<ny<<endl;
                                }
                            }
                        }
                    }
                   // cout<<"현재: "<<arr[i][j]<<"예정: "<< arr[nx][ny]<<endl;
                    
                }
            }
        }
    }
    
    //Show(cTemp);
    //cout<<"#################################"<<endl;
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<y; ++j)
        {
            arr[i][j] = cTemp[i][j];
        }
    }
    
    return;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    x=storage.size();
    y=storage[0].length();
    for(int i=0;i<storage.size();++i)
        for(int j=0;j<storage[0].length(); ++j)
            arr[i][j]=storage[i][j];
    //cout<<"시작 모델"<<endl;
    //Show(arr);
    for(int i=0;i<requests.size();++i)
    {
        if(requests[i].length() == 1) 
            forkLift(arr,requests[i]); 
        else
            Crain(arr,requests[i]);
        //cout<<"리퀘스트 갯수: "<<requests[i].length()<<endl;
        //cout<<i+1<<"번째 시도 결과"<<endl;
       // Show(arr);
    }
    
    //Show(arr);
            
    for(int i=0;i<storage.size();++i)
        for(int j=0;j<storage[0].length(); ++j)
            if(arr[i][j] != '~')answer++;
    return answer;
}