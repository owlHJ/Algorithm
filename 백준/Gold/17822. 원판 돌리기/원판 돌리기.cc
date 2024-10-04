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
		//cout << "TTTEST" << endl;
		for (int j = 0; j < m; ++j)
		{
			board[i][j] = dqTemp.front();
			dqTemp.pop_front();
		//	cout << board[i][j] << " ";
		}
		//cout << endl;
	}

	return;
}
/*
void DFS(vector<pair<int, int>> (&vPos), bool(&visited)[51][51])
{
	for (int i = 0; i < vPos.size(); ++i)
	{
		int x = vPos[i].first, y = vPos[i].second;

		// 1-1 양끝
		if ((y == 0) || (y == n - 1))
		{
			
		}
		// 1-2 좌우
		else if ((y <= n-2) && (y >=1))
		{

		}

		// 2. 앞뒤
		if()
	}
	// 1. 양 끝 단인지
	
	if(vPos.second())
	// 3. 앞 뒤
}
*/
void Push(queue<Pos>& queue, bool(&visited)[51][51], int x, int y)
{
	visited[x][y] = true;
	board[x][y]   = -1;
	queue.push({ x,y });

	return;
}
/*
void BFS( Pos pos, bool(&visited)[51][51])
{
	queue<Pos>qPos;
	qPos.push(pos);

	while (!qPos.empty())
	{
		Pos temp = qPos.front();
		qPos.pop();

		int iTarget = board[temp.x][temp.y];
		// 1-1 양끝
		if ((temp.y == 0) || (temp.y == n - 1))
		{
			if (temp.y == 0)
			{
				if ((iTarget == board[temp.x][n - 1]) && (!visited[temp.x][n-1]))Push(qPos, visited, temp.x, n - 1);
				if ((iTarget == board[temp.x][1]) && (!visited[temp.x][1]))		 Push(qPos, visited, temp.x, 1);
			}
			if (temp.y == n-1)
			{
				if ((iTarget == board[temp.x][0]) && (!visited[temp.x][1]))		Push(qPos, visited, temp.x, 1);
				if ((iTarget == board[temp.x][n-2]) && (!visited[temp.x][n-2]))	Push(qPos, visited, temp.x, n-2);
			}
		}
		// 1-2 좌우
		else if ((temp.y <= n-2) && (temp.y >=1))
		{
			if ((iTarget == board[temp.x][temp.y - 1]) && (!visited[temp.x][temp.y - 1]))	Push(qPos, visited, temp.x, (temp.y - 1));
			if ((iTarget == board[temp.x][temp.y + 1]) && (!visited[temp.x][temp.y + 1]))	Push(qPos, visited, temp.x, (temp.y + 1));
		}

		// 2. 앞뒤

		//2-1  index over, under flow
		if		((temp.x == n - 1) && (iTarget == board[temp.x - 1][temp.y]) && (!visited[temp.x - 1][temp.y]))	Push(qPos, visited, (temp.x - 1), temp.y);
		else if ((temp.x == 0) &&(iTarget == board[temp.x + 1][temp.y]) && (!visited[temp.x + 1][temp.y]))	Push(qPos, visited, (temp.x + 1), temp.y);

		else if ((temp.x <= n - 2) && (temp.x >= 1))
		{
			if(temp.x == n - 1) if ((iTarget == board[temp.x - 1][temp.y]) && (!visited[temp.x - 1][temp.y]))	Push(qPos, visited, (temp.x - 1), temp.y);
			if(temp.x == n - 1) if ((iTarget == board[temp.x + 1][temp.y]) && (!visited[temp.x + 1][temp.y]))	Push(qPos, visited, (temp.x + 1), temp.y);

		}
	}
}
*/
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
				/*
				{
					nx = (nx == -1) ? n - 1 : 0;
				}
				*/
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
			//vector<pair<int, int>>vPos;
			//vPos.push_back({ i,j });
			Pos temp = { i,j };
			//DFS(vPos, visited);
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

	//	cout <<i+1<< "번째 동작 시작" << endl;
	//	View();
	//	 1.회전
		Turn(vInfo[i]);

	//	cout << "회전 동작 완료" << endl;
//View();
		 //2. 인전합 수 지우기

		RemoveNum();

	//	cout << "인접 한 수 지우기 동작 완료" << endl;
	//	View();
		
		// 3. 보드 숫자 채우기
		FillNum();
	//	cout << "채우기 동작 완료" << endl;
	//	View();
	//	cout << "###################" << endl;
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