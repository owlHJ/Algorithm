//아기 상어 : 16236
//난이도 : 골드3

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct sharkInfo
{
	int x;
	int y;
	int size = 2;
	int cnt = 0;
	int time = 0;
};
struct Pos
{
	int x;
	int y;
};
int n;
int board[21][21];
sharkInfo shark;

void Simulate(int & time);
void Input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
			}
		}
	}
}
void View()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << board[i][j];
		}cout << endl;
	}cout << endl;

	cout << "##################" << endl;
}
void visitView(const bool visited[21][21])
{
	cout << "방문 " << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << visited[i][j];
		}cout << endl;
	}cout << endl;

	cout << "##################" << endl;
}
int main()
{
	Input();
	int time = 0;
	
	Simulate(time);
	
	return 0;
}
bool InRange(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}
bool BFS()
{

	bool visited[21][21] = { false, };

	visited[shark.x][shark.y] = true;

	sharkInfo first = shark;
	first.time = 0;
	int time = INT_MAX;
	queue<sharkInfo>qShark;
	qShark.push(first);

	// 우선순위: 위 왼쪽, 오른쪽, 아래
	int dx[4] = { -1,0,0,1 };
	int dy[4] = { 0,-1,1,0 };
	
	bool bEat = false;
	while(!qShark.empty())
	{
		sharkInfo temp = qShark.front();
		qShark.pop();

		if (temp.time == time)
		{
			if (board[temp.x][temp.y] < shark.size && board[temp.x][temp.y] > 0)//> 0 && board[temp.x][temp.y] < 7)
			{
				if ((temp.x < shark.x) || ((temp.x == shark.x) && (temp.y < shark.y)))
				{
					shark.x = temp.x;
					shark.y = temp.y;

					//cout << "Chk  시간 : " << time << endl;
					//visitView(visited);
				}
			}
			
		}
		else
		{
			for (int i = 0; i < 4; ++i)
			{
				int nx = temp.x + dx[i], ny = temp.y + dy[i];

				// 범위 밖, 방문한 곳이라면 탐색 x
				if ((InRange(nx, ny) == false) || (visited[nx][ny] == true)) continue;

				// Shark 이동 가능 여부
				if (temp.size >= board[nx][ny])
				{
					visited[nx][ny] = true;
					// // 작은먹이, 먹기
					if ((temp.size > board[nx][ny]) && (board[nx][ny] != 0) && bEat == false)
					{
							bEat = true;
							shark.x = nx;
							shark.y = ny;

							++shark.cnt;
							shark.time += (temp.time + 1);
							time = temp.time + 1;
							//cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
							//cout << "Chk  시간 : " << time << endl;
							//visitView(visited);
					}

					//이동 Update
					// 빈공간, 사이즈 같은 먹이, 좌표만 이동
					else
					{
						qShark.push({ nx,ny,temp.size,temp.cnt,(temp.time + 1) });

						//cout << "걸린 시간 : " << temp.time  + 1<< endl;
						//cout << "Chk  시간 : " << time << endl;
						//visitView(visited);
					}
				}

			}
		}
		
	}
	board[first.x][first.y] = 0;
	board[shark.x][shark.y] = 9;
	//visitView(visited);

	return bEat;
}
void Simulate(int & time)
{
	while (true)
	{

		//cout << "먹은 수 : " << time << endl;
		//cout << " 사이즈 : " << shark.size<< endl;
		//cout << "걸린 시간 : " << shark.time << endl;
		//View();
		
		bool bFlag = BFS();
		
		if (bFlag == false)break;
		if (shark.cnt == shark.size)
		{
			shark.cnt = 0;
			++shark.size;
		}
		time++;
	}

	cout << shark.time;

	return;
}