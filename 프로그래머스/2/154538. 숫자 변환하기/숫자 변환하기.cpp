#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
int iAnsCnt = 999999;
int iVisited[1000001];

struct qInfo
{
    int iNow;
    int iCnt;
};

queue<qInfo> q1;

int GetNextNum(const int &iNow, const int &iCase, const int &iTarget, const int &sumNum)
{
    int iRet = 0;

    switch (iCase)
    {
        case 0:
            iRet = iNow + sumNum;
            break;
        case 1:
            iRet = iNow * 2;
            break;
        case 2:
            iRet = iNow * 3;
            break;
        default:
            break;
    }

    return iRet;
}

void BFS(const int &iTarget, const int &sumNum)
{
    while (!q1.empty())
    {
        qInfo qTemp = q1.front();
        q1.pop();
        
        if (qTemp.iNow == iTarget)
            break;

        for (int i = 0; i < 3; i++)
        {
            int iNextNum = GetNextNum(qTemp.iNow, i, iTarget, sumNum);
            if (iNextNum > iTarget)
                continue;

            if (iVisited[iNextNum] == -1 || iVisited[iNextNum] > qTemp.iCnt + 1)
            {
                iVisited[iNextNum] = qTemp.iCnt + 1;
                q1.push({iNextNum, qTemp.iCnt + 1});
            }
        }
    }
}

int solution(int x, int y, int n)
{
    int answer = 0;

    fill(begin(iVisited), end(iVisited), -1);

    iVisited[x] = 0;
    q1.push({x, 0});

    BFS(y, n);

    answer = (iVisited[y] != -1) ? iVisited[y] : -1;
    return answer;
}
