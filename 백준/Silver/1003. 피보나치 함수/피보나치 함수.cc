#include <iostream>

using namespace std;

int main()
{
  int d[41]={0,1,1};
    for(int i=3;i<41;i++)d[i]=d[i-1]+d[i-2];
   
    
     
   
    
    int n,k;
     cin>>n;
    for(int j=0;j<n;j++)
    {
       cin>>k;
            if(k == 0) cout<<"1 0\n";
    else if (k == 1) cout<<"0 1\n";
    else  cout<<d[k-1]<<" "<<d[k]<<"\n"; 
  
      
    }
    
    
    return 0;
}