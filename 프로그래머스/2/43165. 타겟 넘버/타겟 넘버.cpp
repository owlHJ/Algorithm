#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer = 0;

void Back(const int &iLimit, vector<int> &vCal, const int &target, const vector<int> &numbers)
{
    if (vCal.size() == iLimit)
    {
        int iTemp = 0;
        for (int i = 0; i < vCal.size(); ++i)
        {
            iTemp += (vCal[i] == 0) ? -1 * numbers[i] : numbers[i];
        }
        if (target == iTemp)
        {
            answer++;
        }
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        vCal.push_back(i);
        Back(iLimit, vCal, target, numbers);
        vCal.pop_back();
    }

    return;
}

int solution(vector<int> numbers, int target)
{
    vector<int> vCal;
    Back(numbers.size(), vCal, target, numbers);
    return answer;
}
