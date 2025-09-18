#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

int maxNum = INT_MIN;
bool visited[11]={false,};
void back2(vector<int> &vTemp, int limit,vector<vector<int>> &vRoll)
{
    if(vTemp.size() == limit)
    {
        vRoll.push_back(vTemp);
        return;
    }
    for(int i=0;i<6;++i)
    {
        vTemp.push_back(i);
        back2(vTemp,limit,vRoll);
        vTemp.pop_back();
    }
    
    return;
}
int calWin(vector<int> &diceA, vector<int> &diceB, const vector<vector<int>> &dice) {
    vector<int> arrA, arrB;

    // A의 합 구하기
    function<void(int,int)> dfsA = [&](int idx, int sum) {
        if (idx == diceA.size()) {
            arrA.push_back(sum);
            return;
        }
        for (int x : dice[diceA[idx]]) {
            dfsA(idx+1, sum+x);
        }
    };
    dfsA(0,0);

    // B의 합 구하기
    function<void(int,int)> dfsB = [&](int idx, int sum) {
        if (idx == diceB.size()) {
            arrB.push_back(sum);
            return;
        }
        for (int x : dice[diceB[idx]]) {
            dfsB(idx+1, sum+x);
        }
    };
    dfsB(0,0);

    // B의 합 정렬
    sort(arrB.begin(), arrB.end());

    long long winCount = 0;
    for (int x : arrA) {
        // x보다 작은 arrB 원소 개수 찾기
        int cnt = lower_bound(arrB.begin(), arrB.end(), x) - arrB.begin();
        winCount += cnt;
    }

    return winCount;
}
int calWin2(vector<int> &diceA,vector<int> &diceB, const vector<vector<int>> &dice)
{
    int iRet = 0;
    vector<int>vTemp;
    vector<vector<int>>vRoll;
    back2(vTemp,diceA.size(),vRoll);
    
    for(int i=0;i<vRoll.size();++i)
    {
            //i는 A의 vRoll 번호
        int sumA=0;
        for(int m=0;m<diceA.size();++m)
        {
            //cout<<vRoll[i][m]<<", ";
            sumA+=dice[diceA[m]][vRoll[i][m]];
        }
        //cout<<endl;
       for(int j=0;j<vRoll.size();++j)
        {
            //j는 B의 vRoll 번호
            int sumB=0;
            for(int m=0;m<diceB.size();++m)
                sumB+=dice[diceB[m]][vRoll[j][m]];
            if(sumA > sumB) iRet++;   
            
        }
    }
     
    
    return iRet;
}
void back(vector<int> &v1,int idx, const int limit, const vector<vector<int>> &dice,vector<int> &answer)
{
    if(v1.size() == limit)
    {
        vector<int>diceA = v1;
        vector<int>diceB;
        for(int i=0;i<dice.size();++i)
            if(!visited[i])diceB.push_back(i);
        
        int iWin = calWin(diceA,diceB,dice);
        if(maxNum < iWin)
        {
            vector<int>vResult;
            for(int i=0;i<diceA.size();++i)
                vResult.push_back(diceA[i]+1);
            
            answer = vResult;
            maxNum = iWin;
        }
        
         maxNum = max(maxNum,calWin(diceA,diceB,dice));
        //cout<<maxNum<<endl;// =
        return;
    }
    
    for(int i=idx; i<dice.size();++i)
    {
        v1.push_back(i);
        visited[i]=true;
        back(v1,i+1,limit,dice,answer);
        visited[i]=false;
        v1.pop_back();
    }
}
vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    vector<int>vDice;
    const int limit = dice.size()/2;
    back(vDice,0,limit,dice,answer);
    //cout<<maxNum<<endl;
    
    
    return answer;
}