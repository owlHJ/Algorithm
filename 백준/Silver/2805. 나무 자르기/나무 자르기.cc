#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;

    // 입력 받기
    cin >> n >> m;
    vector<int> vTree(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vTree[i];
    }

    // 나무 높이 정렬
    sort(vTree.begin(), vTree.end());

    // 이진 탐색 초기화
    int low = 0;                  // 최소 높이
    int high = vTree[n - 1];      // 최대 높이
    int result = 0;               // 최적 높이 저장

    while (low <= high)
    {
        int mid = (low + high) / 2;  // 현재 중간 높이
        long long wood = 0;         // 얻을 수 있는 나무 길이

        // 현재 높이에서 얻을 수 있는 나무 길이 계산
        for (int i = 0; i < n; ++i)
        {
            if (vTree[i] > mid)
                wood += (vTree[i] - mid);
        }

        // 조건에 따라 탐색 범위 조정
        if (wood >= m)  // 필요한 나무 길이를 만족함
        {
            result = mid;   // 현재 높이를 저장
            low = mid + 1;  // 더 높은 높이로 탐색
        }
        else  // 필요한 나무 길이를 만족하지 못함
        {
            high = mid - 1; // 더 낮은 높이로 탐색
        }
    }

    // 결과 출력
    cout << result << endl;
    return 0;
}
