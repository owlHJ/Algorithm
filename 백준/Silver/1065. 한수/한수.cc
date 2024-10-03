#include <iostream>
#include <string.h>
using namespace std;



int main() {
	
	int n,cnt=0;
	
	cin>>n;
	for(int i=1;i<n+1;i++)
	{
		if(i<100)cnt++;
		else
			{
				string a;
				a=i;
				int m=i,k1=0,k2=0;
			
					a[2]=m%10;
					m=m/10;
					a[1]=m%10;
					a[0]=m/10;
			
				k1=a[1]-a[0];
				k2=a[2]-a[1];
				
				if(k1==k2)
				{
					cnt++;	
				}
				
			}
	}
	printf("%d",cnt);
	
	return 0;
}