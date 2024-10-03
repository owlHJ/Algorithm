#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct INFO {
    int day;
    int score;
};

int n;
vector<INFO> vInfo;
int answer = 0;

void BackTracking(int day, int score) {
    if (day > n) return; // 종료 조건

    if (day == n) {
        answer = max(answer, score);
        return;
    }

    // day번째 상담을 선택하는 경우
    if (day + vInfo[day].day <= n + 1) {
        BackTracking(day + vInfo[day].day, score + vInfo[day].score);
    }

    // day번째 상담을 선택하지 않는 경우
    BackTracking(day + 1, score);
}
int main() {
    cin >> n;
    vInfo.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> vInfo[i].day >> vInfo[i].score;
    }

    BackTracking(0, 0);
    cout << answer << endl;

    return 0;
}
