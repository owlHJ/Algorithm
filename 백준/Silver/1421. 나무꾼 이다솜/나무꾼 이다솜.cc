#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, C, W; cin >> N >> C >> W;
    int tree[N]; for (int i = 0; i < N; i++) cin >> tree[i];

    // 나무 하나를 L의 길이가 나오게 자르면 q개 및 나머지 길이 r이 나온다.
    // 나머지 길이가 있다면 q번 잘라야 하며, 나머지 길이가 없다면(딱 맞게 잘린다면) (q-1)번 잘라야 한다.
    // 팔지 않는 것이 이득일 수 있음을 알아야 한다.
    ll answer = 0;
    for (int L = 1; L <= 10000; L++){ // 1부터 10000까지의 길이에 따른 벌 수 있는 돈을 전부 구해보자.
        ll result = 0;
        for (int i = 0, q, r; i < N; i++){
            q = tree[i] / L; r = tree[i] % L;
            result += max(0, r ? (q * L * W - q * C) : (q * L * W - (q - 1) * C));
        }
        answer = max(answer, result);
    }

    cout << answer;
}