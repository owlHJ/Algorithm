#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct DiceInfo
{
    int x;
    int y;
    int score;
    int dir = 1;
    int arr[6];
};
//up right down left
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, k;
int board[21][21];
DiceInfo dice;
void Init();
bool InRange(const int x, const int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void Move(int& dir)
{
    int temp[6] = { 0, };
    int nx = dice.x + dx[dir];
    int ny = dice.y + dy[dir];
    if (InRange(nx, ny) == false)
    {
        dir = (dir + 2) % 4;
        nx = dice.x + dx[dir];
        ny = dice.y + dy[dir];
    }
    dice.x = nx;
    dice.y = ny;

    switch (dir)
    {
        //북
    case 0:
        temp[0] = dice.arr[4];      //front
        temp[1] = dice.arr[1];      //right
        temp[2] = dice.arr[2];      //left
        temp[3] = dice.arr[5];      //back
        temp[4] = dice.arr[3];      //down
        temp[5] = dice.arr[0];      //up
        break;
        //동
    case 1:
        temp[0] = dice.arr[2];      //left
        temp[1] = dice.arr[0];      //up
        temp[2] = dice.arr[3];      //down
        temp[3] = dice.arr[1];      //right
        temp[4] = dice.arr[4];      //front
        temp[5] = dice.arr[5];      //back
        break;
        //남
    case 2:
        temp[0] = dice.arr[5];      //back
        temp[1] = dice.arr[1];      //right
        temp[2] = dice.arr[2];      //left
        temp[3] = dice.arr[4];      //front
        temp[4] = dice.arr[0];      //up
        temp[5] = dice.arr[3];      //down
        break;
        //서
    case 3:
        temp[0] = dice.arr[1];      //right
        temp[1] = dice.arr[3];      //down
        temp[2] = dice.arr[0];      //up
        temp[3] = dice.arr[2];      //left
        temp[4] = dice.arr[4];      //front
        temp[5] = dice.arr[5];      //back
        break;
        // Error
    default:
        break;

    }
    //Dice Info Update
    for (int i = 0; i < 6; ++i)
    {
        dice.arr[i] = temp[i];
    }
    
    return;
}
struct Pos
{
    int x;
    int y;
    int cnt;
};

int BFS(Pos pos, const int num)
{
    int iRet = 0;
    bool visited[21][21] = { 0, };
    visited[pos.x][pos.y] = true;
    queue<Pos> qPos;
    qPos.push(pos);

    while (!qPos.empty())
    {
        Pos temp = qPos.front();
        qPos.pop();
        //iRet = max(iRet, temp.cnt);
        ++iRet;
        for (int i = 0; i < 4; ++i)
        {
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];

            if ((InRange(nx, ny) == false) || (visited[nx][ny] != false) || (board[nx][ny] != num)) continue;
            visited[nx][ny] = true;
            qPos.push({ nx,ny,temp.cnt + 1 });
        }
    }

    return iRet;
}
void GetScore(DiceInfo& info)
{
    Pos pos = { info.x, info.y };
    int B = board[pos.x][pos.y];
    //칸 (x, y)에 대한 점수는 다음과 같이 구할 수 있다. (x, y)에 있는 정수를 B라고 했을때, 
    //(x, y)에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수 C를 모두 구한다. 
    int C = BFS(pos, B);
    //이때 이동할 수 있는 칸에는 모두 정수 B가 있어야 한다. 여기서 점수는 B와 C를 곱한 값이다.
   
    if (C > 0)
    {
        dice.score += B*C;
    }
    
    return;
}
void ChoiceDir(const int A, const int B)
{
    if (A > B)
    {
        //clockwise
        //CW
        dice.dir = (dice.dir + 1) % 4;
    }
    else if (A < B)
    {
        //conterclockwise
        //CCW
        // 북 동 남 서 
        dice.dir = (dice.dir + 3) % 4;
    }
    else
    {
        // A==B, No Action
    }
    return;
}
void Simulate()
{
    //1. Move
    Move(dice.dir);
    //2. GetScore
    GetScore(dice);
    //3. Compare A,B Choice Direction
    ChoiceDir(dice.arr[3], board[dice.x][dice.y]);


    return;
}
int main()
{
    Init();
 


    for (int i = 0; i < k; ++i)
    {
        Simulate();
    }

    cout << dice.score;

    return 0;
}
void Init()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }
    // 위 오른쪽, 왼쪽, 아래, 앞, 뒤
    dice.arr[0] = 1;
    dice.arr[1] = 3;
    dice.arr[2] = 4;
    dice.arr[3] = 6;
    dice.arr[4] = 5;
    dice.arr[5] = 2;

    return;
}