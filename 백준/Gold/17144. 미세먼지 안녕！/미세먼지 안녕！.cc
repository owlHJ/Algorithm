/*
미세먼지 안녕! : 17144
난이도 : 골드 4
*/
// 1. 확산의 개념 
//		1-1 Update 될 정보를 Temp에 기록한다.
//		1-2 Temp에 Board에 대한 정보를 +한다.
//		1-3 Board = Temp 작업을 한다.

#include <iostream>

using namespace std;

int r, c, t;
int board[51][51];
int robotBot;
int robotTop;
bool InRange(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}
void View()
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << board[i][j] << " ";
		}cout << endl;
	}cout << endl;
}
void DustSpread()
{
	int dx[4] = { 0,1,-1,0 };
	int dy[4] = { 1,0,0,-1 };

	int tempBoard[51][51] = { 0 };
	tempBoard[robotBot][0] = -1;
	tempBoard[robotTop][0] = -1;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			// 먼지가 존재한다
			if (board[i][j] > 0) //((board[i][j] != 0) && (board[i][j] != -1))
			{
				int spreadAmount = board[i][j] / 5;
				int spreadCount = 0;

				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					// 벽, 공기청정기가 아니다.
					if (InRange(nx, ny) == false) continue;
					if (board[nx][ny] != -1)
					{
						tempBoard[nx][ny] += spreadAmount;
						++spreadCount;
;					}
				}
				tempBoard[i][j] += board[i][j] - (spreadAmount * spreadCount);
			}
		}
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			board[i][j] = tempBoard[i][j];
		}
	}

	return;
}
void ClockWise(int row)
{
	// 시계방향 동 남 서 북
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	int x = row, y = 0;
	int prev = 0;
	int idx  = 0;
	
	while (true)
	{
		int nx = x + dx[idx];
		int ny = y + dy[idx];

		// 바람 방향 바꾸기
		if (InRange(nx, ny) == false)
		{
			++idx;
			continue;
		}
		
		if ((nx == row) && (ny == 0))break;
		
		int temp = board[nx][ny];
		board[nx][ny] = prev;
		prev = temp;
		x = nx, y = ny;

	}
}
void unClockWise(int row)
{
	// 반 시계방향 동 북 서 남
	int dx[] = { 0, -1, 0, 1 };
	int dy[] = { 1, 0, -1, 0 };

	int x = row, y = 0;
	int prev = 0;
	int idx = 0;

	while (true)
	{
		int nx = x + dx[idx];
		int ny = y + dy[idx];

		// 바람 방향 바꾸기
		if (InRange(nx, ny) == false)
		{
			++idx;
			continue;
		}

		if ((nx == row) && (ny == 0))break;

		int temp = board[nx][ny];
		board[nx][ny] = prev;
		prev = temp;
		x = nx, y = ny;
	}
}
int main()
{
	cin >> r >> c >> t;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == -1) robotBot = i;
		}
	}
	robotTop = robotBot - 1;
	int time = 0;
	while (time < t)
	{
		++time;
		//1. 미세먼지가 확산된다
		DustSpread();

		//2. 공기청정기가 작동한다.
		ClockWise(robotBot);
		unClockWise(robotTop);

	}

	long long answer = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			answer = (board[i][j] > 0) ? answer + board[i][j] : answer;

	cout << answer;

	return 0;
}