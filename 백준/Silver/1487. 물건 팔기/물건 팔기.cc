#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<string>

using namespace std;

//완전탐색 
vector<pair<int, int>>v1;
int n;


void Simulate(int num) {

    for (int i = num; i < n; i++) {

    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v1.push_back(make_pair(a, b));
    }
    sort(v1.begin(), v1.end());

    pair<int, int>answer = make_pair(0, 0);
    for (int i = 0; i < n; i++) {//앞에서 부터 선택 0,1
        int cost = 0;
       // cout << i << "번째 연산 시작 " << endl;
        for (int j = i; j < n; j++) {// 나머지 다 선택
            if (v1[i].first <= v1[j].first && v1[i].first - v1[j].second > 0) {//지불 의사 비용보다 작아야 선택의미 있음 
         //       cout << j << "번째 " << "  : " << v1[i].first - v1[j].second << " -> ";
                cost += v1[i].first - v1[j].second;
         //       cout<<cost<< endl;
            }
        }
        
        if (cost > answer.first) {
            //cout<<"@"<<"  "<<cost;
            answer = make_pair(cost, v1[i].first);
        }
    }
    cout << answer.second;

    return 0;
}