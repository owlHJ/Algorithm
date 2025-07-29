#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int calculate(const int & num)
{
    int iRet = 0;
    int idx = 1;
    int iTemp = num;
    while(true)
    {
        iTemp = iTemp / 10;
        if(iTemp == 0) break;
        iRet = iTemp % 10;
    }
    
    return iRet;
}
bool cmp2(int left, int right)
{
    left = (left >= 10) ? (calculate(left)) : left;
    right = (right >= 10) ? (calculate(right)) : right;
    
    return left > right;
}
bool cmp3(int left, int right)
{
    return (left%10) >(right%10);
}
bool cmp(int a, int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}
string solution(vector<int> numbers) {
    string answer;
    sort(numbers.begin(),numbers.end(),cmp);
    
    for(int i=0;i<numbers.size();++i)
    {
        answer += to_string(numbers[i]);    
    }
    if(answer == string(answer.length(), '0'))
        return "0";
    

    return answer;
}