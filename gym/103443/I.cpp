#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int M = N * N / 2;

int tot, dp1[N][M], dp2[N][M], t, n, x;
vector<int> d1, d2;

void clear(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            dp1[i][j] = dp2[i][j] = false;
    d1.clear();
    d2.clear();
    tot = 0;
}

int solve(){
    if(tot < 0)
        return -1;
    dp1[0][0] = dp2[0][0] = true;
    for(int i : d1)
        for(int j = N - 1; j; j--)
            for(int k = 0; k + i < M; k++)
                dp1[j][k + i] |= dp1[j - 1][k];
    for(int i : d2)
        for(int j = N - 1; j; j--)
            for(int k = 0; k + i < M; k++)
                dp2[j][k + i] |= dp2[j - 1][k];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M && j <= tot; j++)
            if(tot - j < M && dp1[i][j] && dp2[i][tot - j])
                return i;
    return -1;
}

int main(){
    scanf("%d", &t);
    while(t--){
        clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &x);
            tot -= x * i;
            if(x == 1)
                d1.push_back(i);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &x);
            tot += x * i;
            if(x == 2)
                d2.push_back(i);
        }
        printf("%d\n", solve());
    }
    return 0;
}