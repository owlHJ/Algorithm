#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<string>

using namespace std;
vector <pair<int, int>> v;

int main(){
    int n, w,t;
    int cnt;
 
    cin >> n;
 
    for(int i = 0; i < n; i++){
        cin >> w >> t;
        v.push_back(make_pair(w,t));
    }
 
    for(int i = 0; i < n; i++){
        cnt = 1;
        for(int j = 0; j < n; j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second ){
                cnt++;
             // || v[i].first < v[j].first && v[i].second == v[j].second || v[i].first == v[j].first && v[i].second < v[j].second   ){
      
            }
        }
        cout << cnt << endl;
    }


    return 0;
}