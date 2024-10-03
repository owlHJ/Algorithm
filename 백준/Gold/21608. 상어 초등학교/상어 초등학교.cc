#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int score = 0;
struct StudentInfo
{
	int name;
	int arr[4];
};
struct SeatInfo
{
	int num,blank,x, y;
};
int n;
StudentInfo board[21][21];
vector<StudentInfo> vStudents;
void InPut()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			StudentInfo temp;
			cin >> temp.name;

			for (int j = 0; j < 4; ++j)
			{
				cin >> temp.arr[j];
			}

			vStudents.push_back(temp);
		}
	}

	return;
}
bool InRange(const int& x, const int& y)
{
	return x >= 0 and x < n and y >= 0 and y < n;
}
pair<int,int> FindInfo(const int &x, const int &y, const int (&arr)[4])
{
	pair<int, int> iRet = { 0, 0 };
	int dx[4]	= { 0,1,0,-1 };
	int dy[4]	= { 1,0,-1,0 };

	for (int m = 0; m < 4; ++m)
	{
		int nx = x + dx[m];
		int ny = y + dy[m];
		if (InRange(nx, ny) == false) continue;
		if (board[nx][ny].name == 0)++iRet.second;

		for (int k = 0; k < 4; ++k)
		{
			if (arr[k] == board[nx][ny].name)++iRet.first;
		}
	}

	return iRet;
}
SeatInfo SelectSeat(StudentInfo& student)
{
	SeatInfo seat = { -1,-1,-1,-1 };  // 초기화: -1로 설정하여 이후 갱신할 수 있도록 함
	int maxNum = -1, maxBlank = -1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j].name == 0)  // 빈 자리인 경우만 체크
			{
				pair<int, int> info = FindInfo(i, j, student.arr);
				int num = info.first;
				int blank = info.second;

				// 우선순위에 따라 갱신
				if (num > maxNum || (num == maxNum && blank > maxBlank) ||
					(num == maxNum && blank == maxBlank && (i < seat.x || (i == seat.x && j < seat.y))))
				{
					seat = { num, blank, i, j };
					maxNum = num;
					maxBlank = blank;
				}
			}
		}
	}

	return seat;
}

/*
SeatInfo SelectSeat(StudentInfo &student)
{
	const int& name = student.name;

	// 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
	// 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
	// 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
	// num, black, x, y
	SeatInfo seat = { 0,0,0,0};

	int maxNum = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j].name == 0)
			{
				// 상하좌우에 나를 좋아하는 학생의 수 찾기
				pair<int,int>info = FindInfo(i , j, student.arr);
				int num		= info.first;
				int blank	= info.second;
				if (maxNum < num)
				{
					seat	= { num,blank,i,j };
					maxNum	= num;
				}
				else if (maxNum == num)
				{
					if (seat.blank < blank)
					{
						seat = { num,blank,i,j };
					}
					else if (seat.blank == blank)
					{
						if ((seat.x > i) or ((seat.x == i) and (seat.y > j)))
						{
							seat = { num,blank,i,j };
						}
					}
				}

			}
			
		}
	}

	return seat;
}
*/
int main()
{
	InPut();

	for (int i = 0; i < vStudents.size(); ++i)
	{
		SeatInfo temp = SelectSeat(vStudents[i]);
		board[temp.x][temp.y] = vStudents[i];
	}


	//cout << "정답지" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			//cout << board[i][j].name << " ";
			pair<int, int>info = FindInfo(i, j, board[i][j].arr);
			int num = info.first;
			int blank = info.second;
			switch (num)
			{
			case 0 :
				score += 0;
				break;\
			case 1:
				score += 1;
				break;
			case 2:
				score += 10;
				break;
			case 3:
				score += 100;
				break;
			case 4:
				score += 1000;
				break;
			}
		}
	}

	//cout << "총점 : " << score << ", 획득: " << temp.num << endl;

	cout << score;


	return 0;
}