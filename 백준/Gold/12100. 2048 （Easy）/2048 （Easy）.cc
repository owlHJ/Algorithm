// 2048(Eazy) : 12100
// 난이도 : 골드 1

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int board[21][21];
bool bCheck[21][21];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int answer = 0;
void View(int map[21][21])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
struct MapInfo
{
	int cnt=0;
	int arr[21][21];
	// 생성자 
	MapInfo(int initialCnt, int sourceArr[21][21])
	{
		cnt = initialCnt;
		for (int i = 0; i < 21; ++i)
		{
			for (int j = 0; j < 21; ++j)
			{
				arr[i][j] = sourceArr[i][j];
			}
		}
	}
};
int ValMaxNum(const MapInfo & map)
{
	int iRet = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			iRet = max(iRet, map.arr[i][j]);
		}
	}

	return iRet;
}
void Rotate(MapInfo & nextBoard)
{
	int temp[21][21] = { 0, };
	//ClockWise

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp[i][j] = nextBoard.arr[n - 1 - j][i];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			nextBoard.arr[i][j] = temp[i][j];
		} 
	}

}
void Moving(MapInfo& map, const int& dir)
{	// gravity
	for (int i = 0; i < n; ++i)
	{
		int prevRow = n - 1;
		for (int j = n - 1; j >= 0; --j)
		{
			if (map.arr[j][i] != 0)
			{
				int temp = map.arr[j][i];
				int tempIdx = j;
				map.arr[j][i] = 0;
				// 이동O
				if (prevRow != j)
				{
					if (temp == map.arr[prevRow][i])
					{
						map.arr[prevRow][i] *= 2;
						--prevRow;
					}
					else
					{
						prevRow = (map.arr[prevRow][i] == 0) ? prevRow : --prevRow;
						map.arr[prevRow][i] = temp;
					}
				}
				// 이동 X
				else
				{
					if (prevRow == n - 1)
					{
						map.arr[prevRow][i] = temp;

					}
					// 같을 때
					else if (temp == map.arr[prevRow + 1][i])
					{
						map.arr[prevRow + 1][i] *= 2;
					}
					else
					{
						//다를 때 
						map.arr[prevRow][i] = temp;
						prevRow--;
					}
				}
			}
		}
	}

	return;
}
void Simulate()
{
	queue<MapInfo>qMap;
	qMap.push({ 0,board });
	while (!qMap.empty())
	{
		MapInfo temp = qMap.front();
		qMap.pop();
		//cout << "#############" << endl;
		//cout << temp.cnt << "번째 " << endl;
		//View(temp.arr);
		if (temp.cnt == 5)
		{
			int maxBlock = ValMaxNum(temp);
			answer = max(answer, maxBlock);
		}
		else
		{
			for (int i = 0; i < 4; ++i)
			{
				MapInfo nextBoard = temp;
				// 동작 구현
				for (int j = 0; j < i; ++j)
				{
					//90도 회전
					Rotate(nextBoard);
				}
				// 아래로 이동
				Moving(nextBoard,i);
				++nextBoard.cnt;
				
				// Queue Push
				qMap.push(nextBoard);
			}
		}
	}
	return;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	Simulate();
	cout << answer;

	return 0;
}