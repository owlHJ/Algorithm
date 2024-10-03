#include <iostream>
#include <vector>
using namespace std;

int n, l;
int board[101][101];
int answer = 0;

void Input() {
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
}

bool Chkval(vector<int>& vRoad) {
    int size = vRoad.size();
    vector<bool> used(size, false);  

    for (int i = 0; i < size - 1; ++i) {
        if (vRoad[i] == vRoad[i + 1]) {
            continue; 
        }

        if (abs(vRoad[i] - vRoad[i + 1]) > 1) {
            return false;  
        }

        if (vRoad[i] < vRoad[i + 1]) {
            for (int j = 0; j < l; ++j) {
                if (i - j < 0 || vRoad[i - j] != vRoad[i] || used[i - j]) {
                    return false;
                }
                used[i - j] = true; 
            }
        }
        else {
            for (int j = 1; j <= l; ++j) {
                if (i + j >= size || vRoad[i + j] != vRoad[i + 1] || used[i + j]) {
                    return false;
                }
                used[i + j] = true;
            }
        }
    }

    return true;
}

void Simulate() {
    for (int i = 0; i < n; i++) {
        vector<int> road;
        for (int j = 0; j < n; ++j) {
            road.push_back(board[i][j]);
        }
        if (Chkval(road)) {
            ++answer;
        }
    }

    for (int i = 0; i < n; i++) {
        vector<int> road;
        for (int j = 0; j < n; ++j) {
            road.push_back(board[j][i]);
        }
        if (Chkval(road)) {
            ++answer;
        }
    }

    cout << answer;
}

int main() {
    Input();
    Simulate();

    return 0;
}