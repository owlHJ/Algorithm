//0,0 -> 올리는칸
// 0,n-1 ->내리는칸
// 로봇을 올리는 위치에 올리거나 로봇이 어떤 칸으로 이동하면 
//그 칸의 내구도는 즉시 1만큼 감소한다

#include<iostream>
#include<vector>
#include<deque>

using namespace std;
deque<int>belt;
deque<bool>robot;

vector<pair<int, int>>v1;
int n, protect,k;

//->방향으로 이동
void Change() {
	belt.push_front(belt.back());
	belt.pop_back();

	robot.push_front(robot.back());
	robot.pop_back();
	//n번째 땅에 내림
	if (robot[n - 1] == true)robot[n - 1] = false;
}


/*

*/
void Next() {
	for (int i = n - 2; i >=0; i--) {
		
			
		if (!robot[i + 1] && robot[i] && belt[i + 1] >= 1) {
			belt[i + 1]--;
			robot[i] = false;
			if (i == n - 2) continue;//어차피 땅
			robot[i + 1] = true;
		}
	
	}
	


}
void Plus() {
	if (belt[0] >= 1 && !robot[0]) {

		belt[0]--;
		robot[0] = true;
	}

}
bool IsPossilbe(){
	int cnt = 0;
	for (int i = 0; i < 2*n; i++) {
		if (!belt[i])cnt++;
	}
	return cnt >=k;

}

int main() {

	int b;
	cin >> n>>k;

	for (int i = 0; i < 2 * n; i++)
	{
		cin >> b;
		belt.push_back(b);
		robot.push_back(false);

	}
	
	int cnt = 0;
	while (true) {
		cnt++;
		Change();
		Next();
		Plus();
		if (IsPossilbe()) {
			break;
		}
	}
	
	cout << cnt;

	return 0;
}