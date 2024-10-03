#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int save[9][9];
pair<int,int> board[9][9];
int N,k;
vector<int>bollet;
vector<int>sellect;
int answer = 0;
//int cnt = 0;
void Input() {
	cin >> N >> k;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			//first 초기 체력, second 게임 체력
			cin >> board[i][j].first;
			board[i][j].second = board[i][j].first;
			save[i][j] = board[i][j].first;
		}
	for (int j = 0; j < k; j++) {
		int num;
		cin >> num;
		bollet.push_back(num);
	}
}
bool InRange(int x, int y) {
	return x >= 0 && x < N&& y >= 0 && y < N;
}
void create(int row, int col) {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,-1,0,1 };//시계방향
	for (int i = 0; i < 4; i++) {
		int curr_y = row + dy[i];
		int curr_x = col + dx[i];
		
		
			if (board[curr_y][curr_x].first > 0 || !InRange(curr_x, curr_y))continue;
			else {
				board[curr_y][curr_x] =
					make_pair(board[row][col].first / 4, board[row][col].first / 4);

			}
		
	}
}
void Game() {
	
	int score = 0;
	//K번의 사격으로 얻을 수 있는 최대값
	for (int i = 0; i < sellect.size(); i++) {

	// 1. 행 선택
	// 1. 열 단위이동 총(가로) 총알 공격력 존재
	// 표적은 1~9 자연수
	// 표적 피-공격력, 관통 x
		int row = sellect[i];
		int wapon = bollet[i];
	//	cout << row << " ";
		for (int j = 0; j < N; j++) {
			if (board[row][j].second >= 1) {
				//cout << "W" << endl;
				if (board[row][j].first >= 10) {
					//보너스
					score += board[row][j].first;
					//cout << score << endl;
					board[row][j] = make_pair(0, 0);
					break;
				}
				else {
					//표적 제거 실패-> 체력깍기
					if (board[row][j].second > wapon) {
						board[row][j].second -= wapon;
						break;
					}
					// 표적 제거 -> 초기 체력만큼 점수
					else {
						score += board[row][j].first;
						//표적 상,하,좌,우 모든 위치에서 1/4 체력 표적 생성
						//단 있으면 생성 x
						create(row, j);
						board[row][j] = make_pair(0, 0);
						break;
                	}
				}
			}
    	}
	}
	if (answer < score)answer = score;
}
void Set() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			//first 초기 체력, second 게임 체력
			board[i][j].first = save[i][j];
			board[i][j].second = board[i][j].first;
		}
}
void Backtraking(int cnt) {

	if (cnt == bollet.size()) {
		Set();
		Game();
		return;
	}

	//모든 경우의수, 모든 순서도 중요
	for (int i = 0; i < N; i++) {
		sellect.push_back(i);
		Backtraking(cnt + 1);
		sellect.pop_back();
	}
}

void Simulate() {
	Backtraking(0);
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Input();
	Simulate();

	cout << answer;



	return 0;
}