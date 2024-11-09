#include <string>
#include <vector>
#include <iostream>


using namespace std;

// Dia, Iron, Stone
int iDamage[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
int iAnswer = 999999;

// pick, life
vector<pair<int, int>> vWapon;
int GetScore(int waponNum, string s1) 
{
    int iMineral = (s1[0] == 'd') ? 0 : -1;
    iMineral = (s1[0] == 'i') ? 1 : iMineral;
    iMineral = (s1[0] == 's') ? 2 : iMineral;
    return iDamage[waponNum][iMineral];
}
void Back(vector<int> picks, vector<string> &minerals, int iCnt, int iScore)
{
    //종료 조건
    if((picks[0] == 0) && (picks[1] == 0) && (picks[2] == 0))
        iAnswer = min(iAnswer, iScore);
    
    // 무기 종류 수
    for(int i=0;i<3;++i)
    {
        // 무기를 고를 수 있다면
        if(picks[i] >0)
        {
            // 무기 고름
            --picks[i];
            
            int iTempScore = 0;
            
            //총 5회 사용 가능
            for(int j=0;j<5;++j)
            {
                // 광석이 없음
                if(iCnt + j == minerals.size())
                {
                    iAnswer = min(iAnswer, (iScore + iTempScore));
                    return;
                }
                iTempScore += GetScore(i,minerals[iCnt + j]);
            }
            Back(picks,minerals,iCnt+5,(iScore + iTempScore)); 
            ++picks[i];
        }
    }
        
}

int solution(vector<int> picks, vector<string> minerals) {
   
    Back(picks, minerals, 0, 0);
    return iAnswer;
}