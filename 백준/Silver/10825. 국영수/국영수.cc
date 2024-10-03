#include <iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;

struct HYU{
  string name;
    int kor,eng,math;
    
};

bool cmp(HYU a, HYU b)
{
    if(a.kor==b.kor&&a.eng==b.eng&&a.math==b.math)return a.name<b.name;
    else if(a.kor==b.kor&&a.eng==b.eng) return a.math>b.math;
    else if(a.kor==b.kor)return a.eng<b.eng;
    else return a.kor>b.kor;
    
    
}


int main()
{
  int n;
  cin>>n;
  
  vector<HYU>v1(n);
  
  for(int i=0;i<n;i++)
  {
      cin>>v1[i].name>>v1[i].kor>>v1[i].eng>>v1[i].math;
      
      
  }
  sort(v1.begin(),v1.end(),cmp);
  
  for(int i=0;i<n;i++)
   cout<<v1[i].name<<"\n";
  
   
   return 0;
}