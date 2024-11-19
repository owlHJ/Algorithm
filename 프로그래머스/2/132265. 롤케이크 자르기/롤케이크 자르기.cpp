#include <string>
#include <vector>
#include <iostream>

using namespace std;
int iLeft;
int iRight;
int arr[10001];
int leftBox[10001];
int solution(vector<int> topping) {
    int answer = -1;
    
    for(int i=0;i<topping.size();++i)
    {
        if(arr[topping[i]] == 0)
        {
            iRight++;
            arr[topping[i]]++;
        }
        else arr[topping[i]]++;
    }
    for(int i=0;i<topping.size();++i)
    {
        if(leftBox[topping[i]] != 0)
        {
            arr[topping[i]]--;
        }
        else
        {
            leftBox[topping[i]]++;
            arr[topping[i]]--;
            iLeft++;
        }
        if(arr[topping[i]] ==0)
        {
            iRight --;
        }
        if(iLeft == iRight)
        {
            answer = (answer == -1) ? 1 : answer +1;
          //  cout<<answer<<endl;
        }
    }
     answer = (answer == -1) ? 0 : answer;
    return answer;
}