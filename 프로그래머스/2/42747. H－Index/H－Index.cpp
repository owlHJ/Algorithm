#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(int a, int b)
{
    return a<b;
}
int solution2(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),cmp);
    
    for(int i=0;i<citations.size();++i)
    {
        int iTemp = citations[i];
        int cnt = citations.size() - i;
        //if(iTemp <= cnt) answer = iTemp;
        if(iTemp > cnt) break;
        answer = iTemp;
       cout<<iTemp<<","<<cnt<<endl;
        while(iTemp == citations[i+1])
        {
            i++;
            if(i == citations.size()) break;
        }
    }
    
    return answer;
}
int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int answer = 0;
    int n = citations.size();

    for (int i = 0; i < n; ++i) {
        int h = n - i; // h편 이상의 논문이 인용 h번 이상
        if (citations[i] >= h) {
            answer = h;
            break; // 더 이상 높은 h는 안 나옴 (정렬된 상태이므로)
        }
    }
    
    return answer;
}
