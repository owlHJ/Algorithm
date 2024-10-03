#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(int a,int b)
{
    return a>b;
}

int main()
{
    vector<int>v1;
    vector<int>v2;
        
        int n,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        v1.push_back(num);
    }
    for(int i=0;i<n;i++)
    {
        cin>>num;
        v2.push_back(num);
    }
    
    sort(v1.begin(),v1.end(),check);//내림차순
    sort(v2.begin(),v2.end());//오름차순
      
     int s=0;
     for(int i=0;i<n;i++)
     s+=(v1[i]*v2[i]);
     
     cout<<s;
      
  
   
   return 0;
}