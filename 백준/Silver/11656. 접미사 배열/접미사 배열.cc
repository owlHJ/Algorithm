#include <iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
    
    vector<string>temp;
    string s;
    cin>>s;
    
   for(int i=0; i<s.size(); i++){
		temp.push_back(s.substr(i, s.size())); //문자열의 i~l까지를 temp[i]에 복사 
	}
   
   sort(temp.begin(),temp.end());
   
   for(int i=0;i<temp.size();i++)
    cout<<temp[i]<<"\n";
    
   
   
   return 0;
}