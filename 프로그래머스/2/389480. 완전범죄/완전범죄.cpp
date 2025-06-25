#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const vector<int>& a, const vector<int>& b)
{
    int diffA = a[0] - a[1];   // A추가손해
    int diffB = b[0] - b[1];

    if (diffA != diffB) return diffA > diffB;          // 1차
    return a[0] * b[1] > b[0] * a[1];   // 2차: 비율 비교 (곱셈으로 분모 제거)
}

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    sort(info.begin(),info.end(),cmp);
    int aSum =0, bSum=0;
    for(int i=0;i<info.size();++i)
    {
        int a = info[i][0];
        int b = info[i][1];
        
        if(m > b+bSum)bSum += b;
        else if(n > a+aSum)aSum +=a;
        else return -1;
    }
    answer =aSum;
    return answer;
}