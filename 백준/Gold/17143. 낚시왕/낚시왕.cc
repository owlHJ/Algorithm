//낚시왕 : 17143
//난이도 : 골드 1
#include <iostream>
#include <vector>

using namespace std;

struct SharkInfo
{
	int x;
	int y;
	int speed;
	int dir;
	int size;
};
struct sharkInfo
{
	int speed;
	int dir;
	int size;
};

int fishKingPos = -1;
int r, c, m;
sharkInfo sharkArr[101][101] = { {0,0,0,}, };
int answer = 0;

//위 아래 오른쪽  왼쪽
//위 아래 오른쪽  왼쪽
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
// 1. 뒤집기는 시간 X

void Simulate();

void Input()
{
	cin >> r >> c >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		sharkArr[x - 1][y - 1] = { s,d - 1,z };
	}
}
int main()
{
	Input();
	Simulate();

	return 0;
}
void MoveFishKing()
{
	++fishKingPos;
}

void CatchShark()
{
	bool CatchFlag = false;
	int y = fishKingPos;
	int x = 1;
	int index = 0;

	for (int i = 0; i < r; ++i)
	{
		//
		if (sharkArr[i][fishKingPos].size != 0)
		{
			//cout << " 획득 포인트 : " << sharkArr[i][fishKingPos].size << endl;
			answer += sharkArr[i][fishKingPos].size;
			//cout << " 총 포인트 : " << answer << endl;
			sharkArr[i][fishKingPos] = { 0,0,0 };
			CatchFlag = true;
			break;
		}
	}

	return;
}
bool InRange(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}
void ChangeDir(sharkInfo& info)
{
	if (info.dir >= 2)
	{
		//2 3
		info.dir = (info.dir == 2) ? 3 : 2;
	}
	else
	{
		info.dir = (info.dir == 0) ? 1 : 0;
	}

	return;
}
void MoveShark()
{
	// 동시에 이동하므로 필요함
	sharkInfo tempArr[101][101] = { {0,0,0,}, };
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (sharkArr[i][j].size != 0)
			{
				// Moving
				int step = sharkArr[i][j].speed;
				int x = i, y = j;
				int dir = sharkArr[i][j].dir;
				//위 아래 오른쪽  왼쪽
				step = ((dir == 0) || (dir == 1)) ? step % ((r-1) *2): step % ((c - 1) * 2);
				while (step != 0)
				{
					int nx = x + dx[sharkArr[i][j].dir];
					int ny = y + dy[sharkArr[i][j].dir];
					if (InRange(nx, ny) == false)
					{
						ChangeDir(sharkArr[i][j]);
						nx = x + dx[sharkArr[i][j].dir];
						ny = y + dy[sharkArr[i][j].dir];
					}


					x = nx;
					y = ny;

					--step;

				}
				//Update
				if (tempArr[x][y].size < sharkArr[i][j].size)
				{
					tempArr[x][y] = sharkArr[i][j];
				}
				/*
				for (int i = 0; i < r; ++i)
				{
					for (int j = 0; j < c; ++j)
					{
						cout << tempArr[i][j].size << " ";
					}cout << endl;
				}cout << endl;
				cout << endl;
				*/
			}
		}
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			sharkArr[i][j] = tempArr[i][j];
		}
	}

}
void UpdateBoard()
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << sharkArr[i][j].size;
		}
	}
}
void View()
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << sharkArr[i][j].size << " ";
		}cout << endl;
	}cout << endl;
	cout << endl;
}
void Simulate()
{
	//상어가 이동한다.
	//cout << fishKingPos + 1 << "번째 " << endl;
	//View();

	//MoveShark();

	while (fishKingPos < c)
	{
		//cout << fishKingPos +1<<"번째 " << endl;
		//View();

		//낚시왕이 오른쪽으로 한 칸 이동한다.
		MoveFishKing();

		//낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다.
		// 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
		CatchShark();
		//cout<< fishKingPos << "열 상어 잡기 " << endl;
		//View();

		//상어가 이동한다.
		MoveShark();

	}
	cout << answer;
}