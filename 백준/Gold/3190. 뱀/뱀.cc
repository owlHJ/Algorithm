#include <iostream>
#include <list>
#include <queue>
#include<list>
#define MAX_NUM 100
#define ASCII_NUM 128

using namespace std;

bool apple[100][100];
queue<pair<int, int>>time_dir;
list<pair<int, int>>snake;

int n, apple_num;
int x, y;
int dir = 0;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool CanGo(int x, int y) {

	if (x == snake.back().first && y == snake.back().second)
		return false;

	return x >= 1 && y >= 1 && x <= n && y <= n;
}
bool IsTwisted(pair<int, int> newHead) {

	// list에서 몸통이랑 겹치는지 판단해준다 .
	list<pair<int, int> >::iterator it;
	for ( it = snake.begin(); it != snake.end(); it++)
		if (newHead == (*it)) {
			return true;
		}
			

	//겹치지 않는다.
	return false;
}

//머리 추가
bool PushFront(pair<int,int> newHead) {

	if (IsTwisted(newHead) == true) {

		return false;
	}
	

	//꼬이지 않으면

	snake.push_front(newHead);

	return true;

}

bool MoveSnake(int nx, int ny) {

	if (apple[nx][ny] == true) {
		apple[nx][ny] = false;
		if (!PushFront(make_pair(nx, ny)))
			return false;
	}
	else {
		//사과가 없으면 꼬리자르기
		snake.pop_back();

		if (!PushFront(make_pair(nx, ny)))
			return false;
	}

	return true;


}


void Simulate() {
	int Time = 0;
	int next_time = time_dir.front().first;
	int next_dir = time_dir.front().second;
	time_dir.pop();

	while (true) {
		

		pair<int, int> head = snake.front();
	///	cout<<"time: "<<Time<<" " << head.first << " " << head.second << endl;
		



		int nx = head.first + dx[dir];
		int ny = head.second + dy[dir];
		if (!CanGo(nx, ny)) {
			cout << Time+1;
			break;

		}
			

		if (!MoveSnake(nx, ny)) {
			
			cout << Time+1;
			break;

		}
	
		Time++;
		if (next_time == Time) {
			dir = (dir+next_dir)%4;
			if (!time_dir.empty()) {
				 next_time = time_dir.front().first;
				 next_dir = time_dir.front().second;
				time_dir.pop();
			}
		}
	}



}


int main() {

	cin >> n >> apple_num;
	for (int i = 0; i < apple_num; i++) {
		int x, y;
		cin >> x >> y;
		apple[x][y] = true;
	}
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		char dir;
		int t;
		cin >> t >> dir;
		int dir_num;
		if (dir == 'D')dir_num = 1;//시계
		else dir_num = 3;//반시계
		time_dir.push(make_pair(t, dir_num));
	}
	x = 1; y = 1;
	snake.push_back(make_pair(x, y));

	Simulate();


	return 0;
}