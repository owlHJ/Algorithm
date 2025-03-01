#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101]; // 최대 101x101까지 사용 (인덱스 0~100)
int R = 3, C = 3;  // 현재 배열의 행, 열 크기

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, c, k;
    cin >> r >> c >> k;
    // 입력은 3x3 배열
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    
    int time = 0;
    while (time <= 100) {
        // 목표 인덱스 보정 (입력은 1-indexed)
        if (r - 1 < R && c - 1 < C && arr[r-1][c-1] == k) {
            cout << time;
            return 0;
        }
        if (time == 100) break;
        time++;
        
        // R 연산: 행의 개수가 열의 개수 이상일 때
        if (R >= C) {
            int newC = 0; // 새 열의 최대 길이
            for (int i = 0; i < R; i++){
                int count[101] = {0}; // 1~100까지 카운팅 (0은 제외)
                for (int j = 0; j < C; j++){
                    if (arr[i][j] != 0)
                        count[arr[i][j]]++;
                }
                vector<pair<int,int>> v;
                for (int num = 1; num <= 100; num++){
                    if (count[num] > 0){
                        v.push_back({num, count[num]});
                    }
                }
                // 등장 횟수 오름차순, 같으면 숫자 오름차순 정렬
                sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                    if (a.second == b.second)
                        return a.first < b.first;
                    return a.second < b.second;
                });
                
                int idx = 0;
                // 정렬된 결과를 "숫자, 등장횟수" 순으로 행에 채워 넣기 (최대 100개까지만)
                for (auto &p : v) {
                    if (idx >= 100) break;
                    arr[i][idx++] = p.first;
                    if (idx >= 100) break;
                    arr[i][idx++] = p.second;
                }
                // 남은 부분은 0으로 채우기
                for (int j = idx; j < 101; j++){
                    arr[i][j] = 0;
                }
                newC = max(newC, idx);
            }
            C = (newC > 100) ? 100 : newC;
        } 
        // C 연산: 열의 개수가 행의 개수보다 클 때
        else {
            int newR = 0; // 새 행의 최대 길이
            for (int j = 0; j < C; j++){
                int count[101] = {0};
                for (int i = 0; i < R; i++){
                    if (arr[i][j] != 0)
                        count[arr[i][j]]++;
                }
                vector<pair<int,int>> v;
                for (int num = 1; num <= 100; num++){
                    if (count[num] > 0)
                        v.push_back({num, count[num]});
                }
                sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                    if (a.second == b.second)
                        return a.first < b.first;
                    return a.second < b.second;
                });
                
                int idx = 0;
                for (auto &p : v) {
                    if (idx >= 100) break;
                    arr[idx++][j] = p.first;
                    if (idx >= 100) break;
                    arr[idx++][j] = p.second;
                }
                // 남은 부분은 0으로 채우기
                for (int i = idx; i < 101; i++){
                    arr[i][j] = 0;
                }
                newR = max(newR, idx);
            }
            R = (newR > 100) ? 100 : newR;
        }
    }
    
    cout << -1;
    return 0;
}
