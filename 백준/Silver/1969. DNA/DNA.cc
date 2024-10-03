#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
#include<climits>
#include<map>

using namespace std;

//완전탐색 
//vector<pair<int, int>>v1;
vector<int>v1;
vector<string>s1;

int n,m;
map<char, int>m1; //key value
int arr[4];

int main() {
    cin >> n>>m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s1.push_back(s);
        v1.push_back(0);
    }
    m1.insert({ 'A', 0 });
    m1.insert({ 'T',0 });
    m1.insert({ 'G',0 });
    m1.insert({ 'C',0 });

    int cost = 0;
    pair<int, string>answer = make_pair(0,"");

    for (int i = 0; i < m; i++) {
        
        for (int j = 0; j < n; j++) {
            if (s1[j][i] == 'A')
                arr[0]++;
            else if (s1[j][i] == 'C')
                arr[1]++;
            else if (s1[j][i] == 'G')
                arr[2]++;
            else if (s1[j][i] == 'T')
                arr[3]++;
        }


        pair<int, int> max_num = { 0,0 };
    //    cout << "Test  : ";
    //    for (int j = 0; j < 4; j++) cout << arr[j] << " ";
    //    cout << endl;

        for (int j = 0; j < 4; j++) {
            if (max_num.first < arr[j]) {
                max_num = { arr[j],j };
            }
        }
    //   cout << "MAX  ->  ";
    //   cout << max_num.first << "  index : " << max_num.second << endl;

        answer.first += n-max_num.first;

        if (max_num.second == 0)
            answer.second += 'A';
        else if (max_num.second == 1)
            answer.second += 'C';
        else if (max_num.second == 2)
            answer.second += 'G';
        else if (max_num.second == 3)
            answer.second += 'T';

        for (int j = 0; j < 4; j++)arr[j] = 0;

    }


    cout << answer.second << endl << answer.first;

    return 0;
}