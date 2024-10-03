#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<queue>
#include<tuple>
#include<cmath>

using namespace std;
queue<pair<int, int>>q1;
//queue<bool>q1;
vector<pair<int, int>>store;
int t, n;
int curr_x, curr_y;
bool visited[101];
pair<int, int>festival;

bool test = false;

void Set() {
	for (int i = 0; i < n; i++)visited[i] = false;
	while (store.size()>0)store.pop_back();
	test = false;
}
int Distance(pair<int, int>st, pair<int, int>last) {
	int x = st.first - last.first;
	int y = st.second - last.second;
	return abs(x) + abs(y);
}
void FindAnswer() {//최적의 스토어를 찾아
	q1.push({ curr_x ,curr_y });
	while (!q1.empty()) {
		int x, y;
		tie(x, y) = q1.front();
		q1.pop();
		if (Distance({x,y},festival) <= 50 * 20) test = true;
		for (int i = 0; i < n; i++) {
			if (Distance(store[i], { x, y }) <= 50 * 20 && !visited[i]) {
				//cout << i << "번째 " << store[i].first<<", "<<store[i].second << endl;
				visited[i] = true;
				q1.push({ store[i] });

			}
		}

	}


}
int main() {

	cin >> t;
	for (int i = 0; i < t; i++) {
		Set();
		cin >> n;
		cin >> curr_x >> curr_y;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			store.push_back({ a,b });

		}
		cin >> festival.first >> festival.second;
		FindAnswer();
		if (test)cout << "happy" << endl;
		else cout << "sad" << endl;

	}
	return 0;
}