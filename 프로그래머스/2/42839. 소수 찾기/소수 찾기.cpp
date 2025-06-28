#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
vector<int> v1;
bool visited[10] ={ false, };
bool isPrime2(int n) {
	for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
		if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}
void Back(string &str1 ,const string &strRef, int idx, const int &limit)
{
    //cout<<str1<<endl;
    
   if(str1.length() != 0)
   {
    int iTemp = stoi(str1);
       //cout<<iTemp<<endl;
    if(isPrime2(iTemp) && iTemp != 1 && iTemp != 0)
        {
            //cout<<"소수 발견: "<<iTemp<<endl;
            bool bFlag =true;
            for(int i=0;i<v1.size();++i)
            {
                if(v1[i] == iTemp)
                {
                    bFlag = false;
                    break;
                }
            }
            if(bFlag == true) v1.push_back(iTemp);
        }
   }
   
    for(int i=0;i<strRef.size();++i)
    {
        if(visited[i]== false)
        {
            str1+=strRef[i];
            visited[i]= true;
            Back(str1,strRef,i+1,limit);
            str1.pop_back();
            visited[i] = false;    
        }
        
    }
      
    return;
}

int solution(string numbers) {
    int answer = 0;
    int limit = numbers.length();
    string strTemp ="";
    Back(strTemp,numbers,0,limit);
    cout<<v1.size()<<endl;
    answer = v1.size();
    return answer;
}