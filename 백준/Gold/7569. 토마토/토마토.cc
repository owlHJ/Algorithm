#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<tuple>
using namespace std;

int tomato[101][101][101];
bool visited[101][101][101];
int m, n, h;
queue<tuple<int, int, int,int>>q1;
int cnt;
int dx[6] = { -1,0,1,0 ,0,0};
int dy[6] = { 0,1,0,-1 ,0,0};
int dh[6] = { 0,0,0,0,-1,1 };

void Set() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int w = 0; w < m; w++) {
				cin >> tomato[i][j][w];
				if (tomato[i][j][w]==1) {
				//	cout << "ㅊ최초" << i << j << w << endl;
					visited[i][j][w] = true;
					q1.push({ i,j,w,0 });
				}
			}
		}
	}

}
int Check() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int w = 0; w < m; w++) {
				if (tomato[i][j][w] == 0) return -1;
			}
		}
	}
	return 1;
}

void CheckVisited() {
	cout << "Visited " << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int w = 0; w < m; w++) {
				cout << visited[i][j][w] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;

}
void CheckTomato() {
	cout << "Tomato " << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int w = 0; w < m; w++) {
				cout << tomato[i][j][w] << " ";
				
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;

}



bool CanGo(int nx, int ny, int nh) {
	return nx >= 0 && nx < n && ny >= 0 && ny < m && nh >= 0 && nh < h;
}

void BFS() {

	while (!q1.empty()) {
		int x, y, h,cnt_temp;
		tie(h,x, y ,cnt_temp) = q1.front();
		q1.pop();
		cnt = cnt_temp;
	//	cout << cnt << " 번째 "<<x<<", "<<y<<" queue siez : "<<q1.size() << endl;
		//CheckTomato();
		//cout << "@@현재 " << h << ", " << x << ", " << y << endl;
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i], ny = y + dy[i], nh = h + dh[i];
			//cout << nh << ", " << nx << ", " << ny << endl;
			if (CanGo(nx, ny, nh) && !visited[nh][nx][ny] && tomato[nh][nx][ny]!=-1 ) {
				
				visited[nh][nx][ny] = true;
				tomato[nh][nx][ny] = 1;
				//cout << cnt_temp + 1<<" 번째" << endl;
				
				q1.push({ nh, nx,ny,cnt_temp+1 });
			}
		}


	}


}

int main() {
	cin >> m >> n >> h; // 가로 세로 높이

	Set();
	BFS();
	//cout << endl;
	//CheckVisited();
	//CheckTomato();
	//cout << "Test" << endl;
	
	if (Check() == 1)cout << cnt;
	else cout << -1;

	

	return 0;
}