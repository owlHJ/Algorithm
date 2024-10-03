//테트로미노: 14500
//난이도 : 골드

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n, m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int board[501][501];
bool visited[501][501];
int answer = 0;
void Simulate();
void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	return;
}
void Rotate(int(&arr)[3][3], const int (&Tetro)[3][3], const int num)
{
	
	int temp[3][3] = { 0 };
	// Deep Copy
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			//arr[i][j] = temp[i][j];
			arr[i][j] = Tetro[i][j];
		}
	}

	// Num Rotate
	for (int k = 0; k < num; ++k)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 2; j >= 0; --j)
			{
				temp[i][2 - j] = arr[j][i];
			}
		}
		//Copy
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				//arr[i][j] = temp[i][j];
				arr[i][j] = temp[i][j];
			}
		}
	}
	
	return;
}
int main()
{
	Input();
	Simulate();

	return 0;
}
void ChangeSide(const bool(&arr)[3][2])
{
	bool temp[3][2] = { false, };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 1; j >= 0; --j)
		{
			temp[i][1 - j] = arr[i][j];
		}
	}
	//View(temp);
}
void ChangeHigh(const bool(&arr)[3][2])
{
	bool temp[3][2] = { false, };
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			temp[j][i] = arr[2 - j][i];
		}
	}
	//View(temp);
}
void Select1(bool(&arr)[2][3], const int& num)
{
	switch (num)
	{
	case 0: // L
		arr[0][0] = true;
		arr[1][0] = true;
		arr[1][1] = true;
		arr[1][2] = true;
		break;
	case 1:// ㅗ
		arr[0][1] = true;
		arr[1][0] = true;
		arr[1][1] = true;
		arr[1][2] = true;
		break;
	case 2: // ㄹ
		arr[1][0] = true;
		arr[1][1] = true;
		arr[0][1] = true;
		arr[0][2] = true;
		break;
	}
	cout << num << " 선택" << endl;

	return;
}
void Select2(bool(&arr)[3][2], const int& num)
{
	switch (num)
	{
	case 0: // L
		arr[0][0] = true;
		arr[1][0] = true;
		arr[2][0] = true;
		arr[2][1] = true;
		break;
	case 1:// ㅗ
		arr[0][0] = true;
		arr[1][0] = true;
		arr[2][0] = true;
		arr[1][1] = true;
		break;
	case 2: // ㄹ
		arr[0][0] = true;
		arr[1][0] = true;
		arr[1][1] = true;
		arr[2][1] = true;
		break;
	}
	cout << num << " 선택" << endl;

	return;
}
int CheckVal(const int (&arr)[3][3])
{
	int iRet = 0;
	for (int i = 0; i < n-2; ++i)
	{
		for (int j = 0; j < m-2; ++j)
		{
			int temp = 0;
			for (int m = 0; m < 3; ++m)
			{
				for (int k = 0; i < 3; ++k)
				{
					if (arr[m][k] != 0)
					{
						temp += arr[i + m][j + k];
					}
				}
			}
			iRet = max(iRet, temp);
		}
	}

	return iRet;
}

int CheckVal(const bool(&arr)[3][2])
{
	int iRet = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = 0; j < m - 2; ++j)
		{
			int temp = 0;
			for (int m = 0; m < 3; ++m)
			{
				for (int k = 0; i < 2; ++k)
				{
					if (arr[m][k] == true)
					{
						temp += arr[i + m][j + k];
					}
				}
			}
			iRet = max(iRet, temp);
		}
	}

	return iRet;
}
bool InRange(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
vector<pair<int, int>>v;
void DFS(int x, int y, int cnt, int sum)
{
	if (cnt == 4)
	{
		//answer = max(answer, sum);
		if (answer < sum)
		{
		//	cout << "DFS" << endl;
		//	cout << "기존 : " << answer << endl;
		//	cout << "변화 : " << sum << endl;
			answer = sum;
		}
		return;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) == true && !visited[nx][ny])
			{
				sum += board[nx][ny];
				
				visited[nx][ny] = true;

				DFS(nx, ny, cnt + 1, sum);

				visited[nx][ny] = false;
				sum -= board[nx][ny];
			}
		}
	}
}
void Tcase(int x, int y, int cnt, int sum)
{
	int temp_x = x, temp_y = y;
	int sum1 = 0;
	if (InRange(x, y))sum += board[x][y];
	if (InRange(x+1, y))sum += board[x+1][y];
	if (InRange(x+2, y))sum += board[x+2][y];
	if (InRange(x+1, y+1))sum += board[x+1][y+1];
	sum1 = max(sum, sum1);
	sum = 0;

	if (InRange(x, y))sum += board[x][y];
	if (InRange(x +1, y))sum += board[x + 1][y];
	if (InRange(x + 2, y))sum += board[x + 2][y];
	if (InRange(x + 1, y - 1))sum += board[x + 1][y - 1];
	sum1 = max(sum, sum1);
	sum = 0;

	if (InRange(x, y))sum += board[x][y];
	if (InRange(x, y+1))sum += board[x][y + 1];
	if (InRange(x, y+2))sum += board[x][y + 2];
	if (InRange(x - 1, y + 1))sum += board[x - 1][y + 1];
	sum1 = max(sum, sum1);
	sum = 0;

	if (InRange(x, y))sum += board[x][y];
	if (InRange(x, y + 1))sum += board[x][y + 1];
	if (InRange(x, y + 2))sum += board[x][y + 2];
	if (InRange(x + 1, y + 1))sum += board[x + 1][y + 1];
	sum1 = max(sum, sum1);
	sum = 0;

	if (answer < sum1)
	{
	//	cout << "Tcase" << endl;
		//cout << "기존 : " << answer << endl;
		//cout << "변화 : " << sum1 << endl;
		answer = sum1;
	}

	return;
}
void Simulate()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			DFS(i, j, 0, 0);
			Tcase(i, j, 0, 0);
		}
	}
	cout << answer;
	return;
}