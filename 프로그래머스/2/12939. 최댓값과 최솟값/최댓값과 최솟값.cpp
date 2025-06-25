#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int iMax = INT_MIN;
    int iMin = INT_MAX;
    
    bool bFlag = false;
    int iTemp = 0;
    string sTemp="";
    for(int i=0;i<s.length();++i)
    {
        if(s[i]==' ')
        {
            iTemp =iTemp = stoi(sTemp);
            sTemp.clear();
            
            if(bFlag) iTemp *=-1;
            bFlag=false;
            
            cout<<iTemp<<endl;
            iMax = (iMax < iTemp) ? iTemp : iMax;
            iMin = (iMin > iTemp)  ? iTemp : iMin;
        }
        else if(s[i]=='-')
        {
            bFlag = true;
        }
        else
        {
            sTemp+=s[i];
        }
    }
    //to_string
    //stoi
    if (!sTemp.empty()) iTemp = stoi(sTemp);
    sTemp.clear();
    if(bFlag) iTemp *=-1;

    cout<<iTemp<<endl;
    iMax = (iMax < iTemp) ? iTemp : iMax;
    iMin = (iMin > iTemp)  ? iTemp : iMin;
    
    answer += to_string(iMin);
    answer += ' ';
    answer += to_string(iMax);
    return answer;
}