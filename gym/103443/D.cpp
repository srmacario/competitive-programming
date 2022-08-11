#include <bits/stdc++.h>
using namespace std;

int d, k, v[16], dp[1 << 16][200], dez[16];

int main(){
    scanf("%d %d", &d, &k);
    dez[0] = 1;
    for(int i = 1; i < 16; i++)
        dez[i] = dez[i - 1] * 10 % k;
    for(int i = 0; i < d; i++)
        scanf("%d", &v[i]);
    sort(v, v + d);
    for(int i = 0; i < (1 << d); i++)
        for(int j = 0; j < k; j++)
            dp[i][j] = -1;
    dp[0][0] = 0;
    for(int i = 0; i < (1 << d); i++)
    for(int j = 0; j < k; j++)
    if(dp[i][j] >= 0)
    for(int ii = 0; ii < d; ii++)
    if((i & (1 << ii)) == 0){
        int q = __builtin_popcount(i);
        int ni = i + (1 << ii);
        int nj = (dez[q] * v[ii] + j) % k;
        dp[ni][nj] = max(dp[ni][nj], ii);
    }
    int j = 0;
    for(int i = 0; i < k; i++)
        if(dp[(1 << d) - 1][i] >= 0)
            j = i;
    int i = (1 << d) - 1;
    int q = d - 1;
    while(i){
        printf("%d", v[dp[i][j]]);
        int nj = (-dez[q] * v[dp[i][j]] + j) % k;
        i -= (1 << dp[i][j]);
        j = (nj + k) % k;
        q--;
    }
    printf("\n");
    return 0;
}