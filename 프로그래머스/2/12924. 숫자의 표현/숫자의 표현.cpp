#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int start = 1;
    int end = 1;
    int sum = 0;
    for(int i=1;i<=n;++i)
    {
        if(sum + i > n)
        {
            while(sum + i > n)
            {
                sum -=start;
                start++;
            }
        }
        sum+=i;
        end = i;
        
        if(sum == n) answer++;
    }
    return answer;
}