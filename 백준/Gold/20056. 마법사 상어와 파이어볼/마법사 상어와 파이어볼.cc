
/*
파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
이동하는 중에는 같은 칸에 여러 개의 파이어볼이 있을 수도 있다.
이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸
	같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
	파이어볼은 4개의 파이어볼로 나누어진다.
	나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
		질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
		속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
질량이 0인 파이어볼은 소멸되어 없어진다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct Info
{
	int x;
	int y;
	int mass;
	int dir;
	int speed;
};
int n, m, k;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<Info>boardNow[51][51];
vector<Info>vFireBall;
void Simulate()
{
	// 겹치는 것을 관리해줄 것
	vector<Info> boardNxt[51][51];
	vector<pair<int, int>>vPosNxt;
	for (int i = 0; i < vFireBall.size(); ++i)
	{
		// Moving Fire Ball
		int nx = vFireBall[i].x + vFireBall[i].speed * dx[vFireBall[i].dir], ny = vFireBall[i].y + vFireBall[i].speed * dy[vFireBall[i].dir];

		//nx = (nx + n) % n;
		//ny = (ny + n) % n;

		nx %= n;
		ny %= n;

		nx = (nx + n) % n;
		ny = (ny + n) % n;

		//board Update
		Info temp = { nx,ny,vFireBall[i].mass, vFireBall[i].dir,vFireBall[i].speed };
		boardNxt[nx][ny].push_back(temp);
		//	vPosNxt.push_back({ nx,ny });
	}
	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			boardNow[i][j] = boardNxt[i][j];

			if (boardNxt[i][j].size() >= 1)
			{
				cout << boardNxt[i][j][0].mass << " ";

			}
			else cout << 0 << " ";

		}cout << endl;
	}cout << endl;
	*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (boardNxt[i][j].size() <= 1) continue;

			// Sum FireBall
			Info temp = { i,j,0,0,0 };
			bool bDir = ((boardNxt[i][j][0].dir % 2) == 0) ? true : false;
			bool bDirflag = ((boardNxt[i][j][0].dir % 2) == 0) ? true : false;
			int left = 0, right = 0;
			bool bFlag = true;
			//bDir = true  -> 짝수
			//bDir = flase -> 홀수
			for (int q = 0; q < boardNxt[i][j].size(); ++q)
			{
				temp.mass += boardNxt[i][j][q].mass;
				temp.speed += boardNxt[i][j][q].speed;
				if ((boardNxt[i][j][q].dir % 2) == 0)
				{
					right++;
				}
				else left++;
				//bool bTempDir = ((boardNxt[i][j][q].dir % 2) == 0) ? true : false;
				//bFlag = (bDir == bTempDir) ? true : false;
				//temp.dir	+= boardNxt[i][j][q].dir;
			}
			temp.mass /= 5;
			temp.speed /= boardNxt[i][j].size();
			temp.dir = ((left == 0 || right == 0)) ? 0 : 1;
			//cout << "Debug 1 dir : " << temp.dir << endl;

			//temp.dir = ((temp.dir % 2) == 0 ) ? 0 : 1;
			//temp.dir = (bFlag == true) ? 0 : 1;

			//cout << "Debug 2 dir : " << temp.dir << endl;
			// Change FireBall
			boardNxt[i][j].clear();
			if (temp.mass == 0) continue;
			for (int q = 0; q < 4; ++q)
			{
				boardNxt[i][j].push_back({ temp.x, temp.y, temp.mass, (temp.dir + (q * 2)),temp.speed });

				//cout << "Debug "<<i<<" dir : " << temp.dir + (q * 2) <<"Speed: "<<temp.speed << endl;
			}
		}
	}

	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			boardNow[i][j] = boardNxt[i][j];

			if (boardNxt[i][j].size() >= 1)
			{
				cout << boardNxt[i][j][0].mass << " ";
			}
			else cout << 0 << " ";

		}cout << endl;
	}cout << endl;
	cout <<"###############" << endl;
	*/
	vFireBall.clear();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			boardNow[i][j] = boardNxt[i][j];

			if (boardNxt[i][j].size() >= 1)
			{
				for (int q = 0; q < boardNxt[i][j].size(); ++q)
				{

					vFireBall.push_back({ boardNxt[i][j][q] });
					//cout << "Debug " << q <<"size: "<< boardNxt[i][j].size()<<"dir : " << boardNxt[i][j][q].dir + (q * 2) << "Speed : " << boardNxt[i][j][q].speed << endl;
				}
			}

		}
	}

	//cout << "@@@@@@@@@@@@@@@@" << endl;

	
	return;
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		//ri, ci, mi, si, di
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		vFireBall.push_back({ (x - 1),(y - 1),m,d,s });
	}

	for (int i = 0; i < k; ++i)
		Simulate();

	int iAns = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (boardNow[i][j].size() >= 1)
			{
				for (int q = 0; q < boardNow[i][j].size(); ++q)
					iAns += boardNow[i][j][q].mass;
			}

		}
	}

	cout << iAns;

	return 0;
}
