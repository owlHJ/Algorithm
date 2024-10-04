#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int n, m, t;

int board[51][51];
struct Info
{
	int num;
	int dir;
	int speed;
};
struct Pos
{
	int x;
	int y;
};
vector<Info>vInfo;
void View()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << board[i][j] << " ";
		}cout << endl;
	}cout << endl;
			
}
void Turn(const Info &info)
{
	for (int i = 0; i < n; ++i)
	{
		int x = i + 1;
		if (x % info.num != 0)continue;
		deque<int> dqTemp;
		for (int j = 0; j < m; ++j) dqTemp.push_back(board[i][j]);

		// Trun on Deque
		for (int j = 0; j < info.speed; ++j)
		{
			// 0인 경우는 시계 방향, 1인 경우는 반시계 방향
			if(info.dir ==0)
			{
				dqTemp.push_front(dqTemp.back());
				dqTemp.pop_back();
			}
			else
			{
				dqTemp.push_back(dqTemp.front());
				dqTemp.pop_front();
			}
		}

		//Update On Vector Board
		for (int j = 0; j < m; ++j)
		{
			board[i][j] = dqTemp.front();
			dqTemp.pop_front();
		}
	}

	return;
}
void Push(queue<Pos>& queue, bool(&visited)[51][51], int x, int y)
{
	visited[x][y] = true;
	board[x][y]   = -1;
	queue.push({ x,y });

	return;
}
bool InRange(const int x, const int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
int BFS(Pos pos, bool(&visited)[51][51])
{
	int iTarget = board[pos.x][pos.y];
	int iRet = 0;
	queue<Pos>qPos;
	visited[pos.x][pos.y] = true;
	qPos.push(pos);
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };


	while (!qPos.empty())
	{
		Pos temp = qPos.front();
		qPos.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int nx = temp.x + dx[i], ny = temp.y + dy[i];
			if (InRange(nx, ny) == false)
			{
				// -1 or n
				if (nx < 0 || nx >= n) continue;

				if (ny < 0 || ny >= m)
				{
					ny = (ny == -1) ? m - 1 : 0;
				}
			}

			if ((visited[nx][ny] == true) || (board[nx][ny] != iTarget) || ((board[nx][ny] == 0)) || (board[nx][ny] == -1)) continue;
			visited[nx][ny] = true;
			board[nx][ny] = -1;
			iRet++;
			qPos.push({ nx,ny });

		}
		
	}

	return iRet;
}
void RemoveNum()
{
	bool visited[51][51] = { false, };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (visited[i][j] == true) continue;

			visited[i][j] = true;
			Pos temp = { i,j };

			int iTemp = BFS(temp, visited);
			if (iTemp >= 1)board[temp.x][temp.y] = -1;
		}
	}
}
void FillNum()
{

	bool bFlag = true;
	float iMean = 0;
	int iCnt  = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == -1)
			{
				bFlag = false;
				board[i][j] = 0;
			}
			else
			{
				iMean += board[i][j];
				iCnt = (board[i][j] == 0) ? iCnt : iCnt + 1;
			}
		}
		
	}

	iMean = (float) iMean / iCnt;
	
	if (bFlag == false) return;
	//cout << "평균: " << iMean;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 0) continue;
			if (board[i][j] > iMean)	  board[i][j] -= 1;
			else if (board[i][j] < iMean) board[i][j] += 1;
		}
	}
}
int main()
{
	cin >> n >> m >> t;

	// Y는 순환, X는 비순환 
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	for (int i = 0; i < t; ++i)
	{
		int tempX, tempD, tempK;
		cin >> tempX >> tempD >> tempK;
		vInfo.push_back({ tempX,tempD,tempK });
	}
	
	for (int i = 0; i < t; ++i)
	{
		// 1.회전
		Turn(vInfo[i]);
		// 2. 인전합 수 지우기
		RemoveNum();
		// 3. 보드 숫자 채우기
		FillNum();
	}
	
	int iAns = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			iAns = (board[i][j] == -1) ? iAns : iAns + board[i][j];
	cout << iAns;
	/*
	번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
	원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
	그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
	없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
	*/



	return 0;
}