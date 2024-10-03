#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
};
int		board[51][51];
bool	chkRainBoard[51][51];
vector<Pos>vCloud;
vector<pair<int, int>>vCommand;

//bool board[51][51];

int n, m;
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
void CloudMove(pair<int,int>Command)
{
	int dir = Command.first;
	int speed = (Command.second) % n;

	for (int i = 0; i < vCloud.size(); ++i)
	{
		vCloud[i].x += speed * dx[dir];
		vCloud[i].y += speed * dy[dir];

		vCloud[i].x = (vCloud[i].x + n) % n;
		vCloud[i].y = (vCloud[i].y + n) % n;
	}

	return;
}
void Rain()
{
	for (int i = 0; i < vCloud.size(); ++i)
	{
		++board[vCloud[i].x][vCloud[i].y];
		chkRainBoard[vCloud[i].x][vCloud[i].y] = true;
	}

	return;
}
void CloudDelete()
{
	vCloud.clear();

	return;
}
bool InRange(const int& x, const int& y)
{
	return x >= 0 and x < n and y >= 0 and y < n;
}
int FindWaterNum(const int x, const int y)
{
	int iRet = 0;

	int dx[4] = { -1,-1,1,1 };
	int dy[4] = { -1,1,1,-1 };
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i]; int ny = y + dy[i];

		if (InRange(nx, ny) == false) continue;
		if (board[nx][ny] > 0) ++iRet;
	}

	return iRet;
}
void CopyWater()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (chkRainBoard[i][j] == true)
			{
				int iTemp = FindWaterNum(i,j);
				
				board[i][j]			+= iTemp;
			}
		}
	}

	return;
}
void MakeCloud()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((board[i][j] >= 2) and (chkRainBoard[i][j] != true))
			{
				vCloud.push_back({ i,j });
				board[i][j] -= 2;
			}
		}
	}

	return;
}
void SetBoard()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			chkRainBoard[i][j] = false;
		}
	}
}
void ViewCloud()
{
	bool arr[51][51] = { false, };
	for (int i = 0; i < vCloud.size(); ++i)
	{
		arr[vCloud[i].x][vCloud[i].y] = true;
	}

	cout << "### Cloud ###" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << arr[i][j] << " ";
		}cout << endl;
	}cout << endl;
}
void ViewBoard()
{
	cout << "### 보드 ###" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << board[i][j] << " ";
		}cout << endl;
	}cout << endl;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		vCommand.push_back({a-1,b});
	}
	vCloud.push_back({ (n - 1),(1-1)});
	vCloud.push_back({ (n - 1),(2-1) });
	vCloud.push_back({ (n - 1 -1),(1-1) });
	vCloud.push_back({ (n - 1 -1),(2-1)});
	for (int i = 0; i < vCommand.size(); ++i)
	{
		SetBoard();
		//cout << i + 1 << "번째 시뮬" << endl;
		//ViewBoard();
		//ViewCloud();
		CloudMove(vCommand[i]);
		//ViewCloud();
		Rain();

		CloudDelete();


		CopyWater();

		//ViewBoard();

		MakeCloud();
	}
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			//cout << board[i][j] << " ";
			answer += board[i][j];
		}//cout << endl;
	}//cout << endl;

	cout << answer;

	return 0;
}