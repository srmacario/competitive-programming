#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 105;
const int K = 2e3 + 5;

int n, m, h[N], v[K];
ll c[N][K];

int maxj;
ll dp[N][K], a[N][K];

//int cost(int i, int j){ return c[i][j] + h[i]; }

bool val(ll mid){
    memset(dp, 63, sizeof(dp));
    for(int i = 1; i <= n; i++) dp[1][i] = 0;
    dp[1][1] = mid;

    // set initial a[i][j]
    for (int i = 1; i <= n; i++) a[i][1] = 1, a[n+1][i] = n;

    for (int j = 2; j <= maxj; j++)
    for (int i = n; i >= 1; i--){
        for (int k = a[i][j-1]; k <= a[i+1][j]; k++) {
        ll v = max(dp[k][j-1] - c[j - 1][i - k], 0ll);
        if(v > 0) v += h[i];

        // store the minimum answer for d[i][k]
        // in case of maximum, use v > dp[i][k]
        if (v > dp[i][j])
            a[i][j] = k, dp[i][j] = v;
        }
    }
    return dp[n + 1][m] > 0;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d", &h[i]);
    for(int i = 1; i <= n; i++){
        int sz;
        scanf("%d", &sz);
        for(int j = 0; j < sz; j++)
            scanf("%d", &v[j]);
        sort(v, v + sz);
        ll sum = 0, h = 0;
        for(int j = 0; j < sz; j++){
            h += v[j];
            sum += h;
            c[i][j] = sum;
        }
    }
    ll lo = 0, hi = 1e18;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        if(val(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%lld\n", lo);
    return 0;
}