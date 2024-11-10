#include <string>
#include <vector>
#include <queue>

using namespace std;
char    cBoard[101][101];
bool    bVisited[101][101];
struct Pos
{
    int x;
    int y;
    int iCnt;
};
queue<Pos>q1;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N,M;
Pos posTarget = {0,0,0};
bool InRange(const int &x, const int &y)
{
    return x >=0 && x<N && y>= 0 && y < M; 
}
Pos GetNextPos(Pos pos, const int &dir)
{
    Pos posNow = pos;
    while(true)
    {
        Pos posNext = {(posNow.x + dx[dir]),(posNow.y + dy[dir]),(pos.iCnt + 1)};
        //가장자리 or 벽 -> 끝
        if((InRange(posNext.x, posNext.y) == false) || (cBoard[posNext.x][posNext.y] == 'D')) break;
        //이동
        posNow = posNext;
    }
    
    return posNow;
}
bool BFS()
{
    while(!q1.empty())
    {
        Pos qTemp = q1.front();
        q1.pop();
        if((qTemp.x == posTarget.x ) && (qTemp.y == posTarget.y))
        {
            posTarget.iCnt = qTemp.iCnt;
            return true;
        }
        for(int i=0;i<4;++i)
        {
            Pos nextPos = GetNextPos(qTemp,i);
            // 반복해서 나온거면, 무시해라
            if(bVisited[nextPos.x][nextPos.y]) continue;
            
            bVisited[nextPos.x][nextPos.y] = true;
            q1.push(nextPos);
        }
    }
    return false;
}
int solution(vector<string> board) {
    int answer = 0;
    N = board.size();
    M = board[0].size();
    Pos posStart = {0,0,0};
    for(int i=0;i<board.size();++i)
    {
        for(int j=0;j<board[0].size();++j)
        {
            if(board[i][j] =='G')
            {
                posTarget.x = i;
                posTarget.y = j;
            }
            if(board[i][j] == 'R')
            {
                posStart.x = i;
                posStart.y = j;
            }
            cBoard[i][j] = board[i][j];
        }
    }
    q1.push(posStart);
    if((posStart.x == posTarget.x) && (posStart.y == posTarget.y))
        answer =0;
    else
    {
        bool bFlag = BFS();
        answer = (bFlag == true) ? posTarget.iCnt : -1;      
    }
    
    return answer;
}