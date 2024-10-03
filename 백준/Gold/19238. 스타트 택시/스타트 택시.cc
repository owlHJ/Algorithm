//3시 20분
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m,k;
int board[21][21];
struct Pos
{
	int x;
	int y;
};
vector<pair<Pos,Pos>>vCustomer;

struct DriverInfo
{
	Pos pos;
	int gas;
};
DriverInfo driver;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void Input()
{
	// Init, Board Info
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	//Dirver Info
	cin >> driver.pos.x >> driver.pos.y;
	--driver.pos.x; --driver.pos.y;
	driver.gas = k;

	//Customer Info
	for (int i = 0; i < m; ++i)
	{
		Pos start, end;
		cin >> start.x >> start.y >> end.x >> end.y;
		--start.x; 	--start.y;
		--end.x; --end.y;
		vCustomer.push_back({ start,end });
		board[start.x][start.y] = 10+i;
	}
}
bool InRange(const int x, const int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}
struct CustomerInfo
{
	Pos pos;
	int cnt;
};
CustomerInfo FindCustomer(void)
{
	CustomerInfo Ret = { {-1,-1},-1 };

	bool visited[51][51] = { false, };
	int iCntFlag = -1;
	//int dist = BFS(driver);
	queue<CustomerInfo>qPos;
	qPos.push({ driver.pos ,0 });
	visited[driver.pos.x][driver.pos.y] = true;

	while (!qPos.empty())
	{
		CustomerInfo temp = qPos.front();
		qPos.pop();
		if ((board[temp.pos.x][temp.pos.y] != 0) && (board[temp.pos.x][temp.pos.y] != 1))
		{
			if (iCntFlag == -1)
			{
				iCntFlag	= temp.cnt;
				Ret			= temp;
			}
			else if (iCntFlag == temp.cnt)
			{/*
				if	((Ret.pos.y > temp.pos.y)	||
					((Ret.pos.y == temp.pos.y)	&& 
					 (Ret.pos.x > Ret.pos.x)))
			*/

			if  ((Ret.pos.x > temp.pos.x) ||
				((Ret.pos.x == temp.pos.x) &&
				 (Ret.pos.y > temp.pos.y)))
			{
					Ret = temp;
			}

			}
		}
		else if ((iCntFlag == -1) || (iCntFlag >temp.cnt))
		{
			for (int i = 0; i < 4; ++i)
			{
				int nx = temp.pos.x + dx[i];
				int ny = temp.pos.y + dy[i];
				int cnt = temp.cnt;

				if ((InRange(nx, ny) == false) || (visited[nx][ny] == true) || (board[nx][ny] == 1)) continue;
				visited[nx][ny] = true;
				qPos.push({ nx,ny,cnt + 1 });

			}
		}
		
	}
	
	return Ret;
}
bool MoveTaxi(CustomerInfo & info)
{
	bool bRet = true;

	int & dist = info.cnt;
	bRet = ((driver.gas - dist) >= 0) ? true : false;
	
	if (bRet == true)
	{
		driver.pos.x = info.pos.x;
		driver.pos.y = info.pos.y;
		driver.gas  -= dist;
		bRet		 = true;
	}

	return bRet;
}
int BFS(Pos endP)
{
	int iRet = 0;
	
	//Init
	bool visited[51][51] = {false,};
	queue<CustomerInfo> qInfo;
	qInfo.push({ driver.pos ,0 });
	visited[driver.pos.x][driver.pos.y] = true;

	while (!qInfo.empty())
	{
		CustomerInfo temp = qInfo.front();
		qInfo.pop();
		if ((temp.pos.x == endP.x) && (temp.pos.y == endP.y))
		{
			iRet = temp.cnt;

			return iRet;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = temp.pos.x + dx[i];
			int ny = temp.pos.y + dy[i];

			if ((InRange(nx, ny) == false) || (visited[nx][ny] == true) || (board[nx][ny] == 1)) continue;

			visited[nx][ny] = true;
			qInfo.push({{ nx,ny },(temp.cnt + 1)});

		}

	}
	
	return iRet;
}
bool MoveCustomer()
{
	bool bRet = true;

	int idx		= board[driver.pos.x][driver.pos.y] - 10;
	Pos endP	= vCustomer[idx].second;

	//cout << "운전 출발 좌표: " << driver.pos.x << ", " << driver.pos.y << endl;
	//cout << "목적지 좌표: " << endP.x << ", " << endP.y << endl;
	//int dist	= abs(driver.pos.x - endP.x) + abs(driver.pos.y - endP.y);
	int dist    = BFS(endP);
	bRet = ((driver.gas - dist) >= 0) ? true : false;
	bRet = (dist == 0) ? false : bRet;
	
	if (bRet == true)
	{
		driver.pos.x = endP.x;
		driver.pos.y = endP.y;
		driver.gas	+= dist;
		bRet = true;
		board[vCustomer[idx].first.x][vCustomer[idx].first.y] = 0;
	}


	return bRet;
}
void View()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << board[i][j] << " ";
		}cout << endl;
	}cout << endl;
}
bool Simulate()
{
	bool bRet		= true;
	int customerNum = vCustomer.size();
	// 현재 위치에서 최단거리 고객 찾기
	// 거리와, 좌표 계산


	for (int i = 0; i < customerNum; ++i)
	{
		//cout << i + 1 << "번째 시작" << endl;
		//View();
		CustomerInfo temp = FindCustomer();
		//cout << "시작 Gas : " << driver.gas << endl;
		//cout << "시작 좌표: " << driver.pos.x << ", " << driver.pos.y << endl;
		//cout << "고객 좌표: " << temp.pos.x << ", " << temp.pos.y << endl;
		bool bFlag = (temp.cnt != -1) ? true : false;
		if (bFlag == false) return bFlag;
		// Move
		bFlag = MoveTaxi(temp);
		if (bFlag == false) return bFlag;
		//cout << "고객 이동후 남은 Gas : " << driver.gas << endl;
		// 고객 태우고 이동하기
		bFlag = MoveCustomer();
		if (bFlag == false) return bFlag;

		//cout << "목적지 이동후 남은 Gas : " << driver.gas << endl;
	//	View();
	//	cout << "######################" << endl;
		// 성공 여부 확인
	}


	return bRet;
}
int main()
{
	Input();

	bool bAns	= Simulate();
	int iAns	= (bAns == true) ? driver.gas : -1;
	
	cout << iAns;

	return 0;
}