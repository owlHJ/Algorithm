#include <iostream>
#include <algorithm>
using namespace std;

int dpSum[301];
int num[301];
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;++i)
    {
        cin>>num[i];
    }
    dpSum[0] = num[0];
    //dpSum[1] = num[1];
    //dpSum[2] = max(num[0],num[1]) + num[2];
    dpSum[1] = num[0] + num[1];
    dpSum[2] = max(num[0] + num[2], num[1] + num[2]);
    for(int i=3;i<n;++i)
    {
        // 선택 2칸 or 1칸 뒤
        dpSum[i] = max((dpSum[i-2]+num[i]),(dpSum[i-3]+ num[i-1]+num[i])) ;
    }

    cout<< dpSum[n-1];

    return 0;
}