#include <iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int>s;
    int n,sum=0;
    cin>>n;
    int num;
    for(int i=0;i<n;i++)//빼기
    {
        cin>>num;
        if(num==0) s.pop();

        else s.push(num);
    }
int k=s.size();
    for(int j=0;j<k;j++)//덧셈
    {
        sum+=s.top();
        s.pop();
    }
    printf("%d",sum);
    
   return 0;
}