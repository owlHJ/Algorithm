#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    vector<int>vTree(n);

    for(int i=0;i<n;++i)
        cin>>vTree[i];
    
    sort(vTree.begin(),vTree.end());

    int low = 0;
    int result  = 0;
    int high = vTree[n-1];


    while(low<=high)
    {
        int mid = (low + high) / 2;

        long long wood = 0;
        for (int i = 0; i < n; ++i)
        {
            if (vTree[i] > mid)
                wood += (vTree[i] - mid);
        }
         

        if(wood >= m)
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout<<result<<endl;
}