#include <string>
#include <vector>
#include <set>

using namespace std;

bool isLive(set<int> &cards1,set<int> &cards2, const int target)
{
    for(set<int>::iterator it = cards1.begin(); it != cards1.end(); ++it)
    {
        int first = *it;
        int second = target - first;
        
//         auto it2 = cards2.find(target - first);
//         if (it2 != cards2.end())
//         {
//             cards1.erase(first);
//             cards2.erase(*it2);
//             return true;
        
//         }
        
        if(cards2.count(second) > 0 && first != second)
        {
            cards1.erase(first);
            cards2.erase(second);
            
            return true;
        }
            
    }
    
    return false;
}
int solution(int coin, vector<int> cards) {
    int answer = 1;
    int target = cards.size()+1;
    int idx =cards.size()/3;
    
    //매 라운드 마다 2장씩 뽑아. -> 
    
    set<int>remove;
    set<int>hands;
    for(int i=0;i<idx;++i)
        hands.insert(cards[i]);
    
    for(int i=idx;i<cards.size();i+=2)
    {
        pair<int,int> recvCard ={cards[i],cards[i+1]};
        remove.insert(recvCard.first);
        remove.insert(recvCard.second);
        
        if(isLive(hands,hands,target))
        {
            coin = coin;
        }
        else if(coin >=1 && isLive(hands,remove,target))
        {
            coin-=1;
        }
        else if(coin >=2 && isLive(remove,remove,target))
        {
            coin-=2;
        }
        else
        {
            break;
        }
        answer++;
    }
    
    return answer;
}