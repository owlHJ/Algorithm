#include <iostream>
#include <stdio.h>
using namespace std;


bool a[10001]={0,};

int test(int idx)
{
  int sum=idx;

    while(1){
    
    	if(idx==0)break;
      sum+=idx%10;
      idx=idx/10;
 

    }
 
 
return sum;
}

int main() {
  
  int m;
  for(int i=0;i<10001;i++)
  {
  	m=test(i);
  	
    a[m]=1;
      
  }
   
    for(int i=0;i<10001;i++)
  {
  	if(a[i]==0)printf("%d\n",i);
  }

 return 0;
}

