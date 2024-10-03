#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
 
long long  a, b, c;
int result = 0;
long long  pow(long long int x, long long int m) {
 
    if (m == 0)
        return 1;
    else if (m == 1)
        return x;
    if (m % 2 > 0)//홀수
        return pow(x, m - 1)*x;
    long long half = pow(x, m / 2);
    half %= c;
    return (half * half) % c;
}
 
int main() {
 
   cin>>a>>b>>c;
 
 
 cout<<pow(a,b)%c;
    
    return 0;
}