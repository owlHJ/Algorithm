// 감시 : 15683
// 난이도: 골드3

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
struct cctvInfo
{
	int x;
	int y;
	int type;
	bool dir[4] = { false, };
};
int board[9][9];
int n, m;
int minBlindSpots = INT_MAX;
vector<cctvInfo>cctv;
void View()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << board[i][j] << " ";
		}cout << endl;
	}
	cout << "##############################" << endl;
	cout << endl;

	return;
}
void Input()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			if ((board[i][j] > 0) && (board[i][j] < 6))
			{
				cctv.push_back({ i,j, board[i][j]});
			}
		}
	}

	return;
}
bool InRange(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
void SetBoard(cctvInfo& _cctv, const int dir)
{
	int x = _cctv.x;
	int y = _cctv.y;
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { 1,0,-1,0 };
	// 방향에 따라서, Board를 9로 세팅한다.
	while (true)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
	
		// 2-9 Out Range,벽 만나면 종료
		if ((InRange(nx, ny) == false) or (board[nx][ny] == 6))break;

		//	2-1 cctv면 건너 뛰기
		if (board[nx][ny] > 0 and board[nx][ny] < 6)
		{
			x = nx;
			y = ny;
			continue;
		}
		
		board[nx][ny] = 9;
		x = nx;
		y = ny;
	}

	return;
}
void SetCCTV(int cnt)
{
	if (cnt == cctv.size())
	{
		int blindSpots = 0;

		// 세팅이 완료되어, 사각지대의 개수를 탐색한다.
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (board[i][j] == 0)
				{
					++blindSpots;
				}
			}
		}

		// 사각지대의 최소 개수로 업데이트한다.
		minBlindSpots = min(minBlindSpots, blindSpots);

		return;
	}
	//1.모든 cctv의 방향을 잡는다.
	for (int dir = 0; dir < 4; ++dir)
	{
		int backUp[9][9];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				backUp[i][j] = board[i][j];

		cctvInfo& curr = cctv[cnt];

		//2. type에 맞춰 Board를 Set한다.
		switch (curr.type)
		{
		case 1:
			SetBoard(cctv[cnt], dir);
			break;
		case 2:
			SetBoard(cctv[cnt], dir);
			SetBoard(cctv[cnt], (dir + 2) % 4);
			break;
		case 3:
			SetBoard(cctv[cnt], dir);
			SetBoard(cctv[cnt], (dir + 1) % 4);
			break;
		case 4:
			SetBoard(cctv[cnt], dir);
			SetBoard(cctv[cnt], (dir + 1) % 4);
			SetBoard(cctv[cnt], (dir + 2) % 4);
			break;
		case 5:
			SetBoard(cctv[cnt], dir);
			SetBoard(cctv[cnt], (dir + 1) % 4);
			SetBoard(cctv[cnt], (dir + 2) % 4);
			SetBoard(cctv[cnt], (dir + 3) % 4);
			break;
		}

		SetCCTV(cnt + 1);
		
		//CCTV의 Board 상태를 복구한다.
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				board[i][j] = backUp[i][j];
			}
		}
	}

	return;
}
int main()
{
	//0. 입력 정보 받기
	Input();

	//CCTV 동작 구현
	SetCCTV(0);
	
	// 출력
	cout << minBlindSpots;

	return 0;
}