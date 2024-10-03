// 골드 4

//지도의 좌표는 (r, c)로 나타내며, r는 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로부터 떨어진 칸의 개수이다. 
// 1. 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 
// 2. 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
//
// 주사위가 이동했을 때 마다 상단에 쓰여 있는 값을	출력

#include <iostream>

using namespace std;
struct Pos
{
	int x;
	int y;
};
Pos posDice;
// 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3
//int dice[6] = { 3,4,5,2,1,6 };
int dice[6] = { 0, };
int n, m, x, y, k;
int board[21][21];
void View(void)
{
	cout << "Board ###" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}

	cout << "Dice ###" << endl;
	for (int i = 0; i < 6; ++i)
		cout << dice[i] << " ";
	cout << endl;

	cout << endl;
}
bool InRange(Pos pos)
{
	return pos.x >= 0 && pos.x < n && pos.y >= 0 && pos.y < m;
}

void Simulate(int call)
{
	//동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
	Pos nPosDice = { 0,0 };
	int temp[6] = { 0, };
	bool bFlag = true;
	switch (call)
	{
	case 1:
		nPosDice = { posDice.x, (posDice.y + 1) };
		if (InRange(nPosDice) == false) { bFlag = false; break; }
		temp[0] = dice[5];
		temp[1] = dice[4];
		temp[2] = dice[2];
		temp[3] = dice[3];
		temp[4] = dice[0];
		temp[5] = dice[1];
		break;
	case 2:
		nPosDice = { posDice.x, (posDice.y - 1) };
		if (InRange(nPosDice) == false) { bFlag = false; break; }
		temp[0] = dice[4];
		temp[1] = dice[5];
		temp[2] = dice[2];
		temp[3] = dice[3];
		temp[4] = dice[1];
		temp[5] = dice[0];
		break;
	case 3:
		nPosDice = { (posDice.x - 1), posDice.y };
		if (InRange(nPosDice) == false) { bFlag = false; break; }
		temp[0] = dice[0];
		temp[1] = dice[1];
		temp[2] = dice[4];
		temp[3] = dice[5];
		temp[4] = dice[3];
		temp[5] = dice[2];
		break;
	case 4:
		nPosDice = { (posDice.x + 1), posDice.y };
		if (InRange(nPosDice) == false) { bFlag = false; break; }
		temp[0] = dice[0];
		temp[1] = dice[1];
		temp[2] = dice[5];
		temp[3] = dice[4];
		temp[4] = dice[2];
		temp[5] = dice[3];
		break;
	default:
		break;
	}
	if (bFlag == true)
	{
		// 이동 성공
		for (int i = 0; i < 6; ++i)
			dice[i] = temp[i];
		posDice = nPosDice;
		// 흡수 하는 기능 
		if (board[posDice.x][posDice.y] == 0)
		{
			// Board Save Dice Bottom Number
			board[posDice.x][posDice.y] = dice[4];
		}
		else
		{
			// 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이
			dice[4] = board[posDice.x][posDice.y];
			board[posDice.x][posDice.y] = 0;
		}
		//View();
		cout<< temp[5] << endl;
		//cout << endl;
	}
}
int main()
{
	cin >> n >> m >> x >> y>>k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}
	posDice = { x,y };
	for (int i = 0; i < k; ++i)
	{
		int call;
		cin >> call;
		Simulate(call);
	}
	

	return 0;
}