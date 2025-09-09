#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
bool isOpen(const char & c1)
{
    if((c1 =='[') || (c1 =='{') || (c1 =='('))
        return true;
    
    return false;
}
bool isCouple (const char target, const char source)
{
    bool bRet = false;
    //if(target == '') return false;
    
    if((target == '{') && source == '}') bRet = true;
    else if((target == '(') && source == ')') bRet = true;
    else if((target == '[') && source == ']') bRet = true;
    
    return bRet;
}
int simulate(string str1)
{
    stack<char>st1;
    
    for(int i=0;i<str1.length();++i)
    {
        if(st1.empty()) st1.push(str1[i]);
        
        else
        {
            if(isOpen(str1[i]))
            {
                st1.push(str1[i]);
            }
            else if (isCouple(st1.top(),str1[i]))
            {
                st1.pop();
            }
            else
            {
                return 0;   
            }
        }
    }
    if(!st1.empty()) return 0;
    
    return 1;
}
string shiftString(const string & s1,const int shiftNum)
{
    string strRet="";
    int iCnt = 0;
    int idxMax = s1.length();
    while(iCnt < idxMax)
    {
        strRet += s1[(iCnt+shiftNum) % (idxMax)];
        iCnt++;
    }
    //cout<<iCnt<<","<<s1.length()<<endl;
    return strRet;
}
int solution(string s) {
    int answer = -1;
    answer = 0;
    for(int i=0;i<s.length();++i)
    {
        string sTemp = s;
       // cout<<"###"<<endl;
        //cout<<shiftString(sTemp,i)<<endl;
        answer+=simulate(shiftString(sTemp,i));
    }
    
    return answer;
}