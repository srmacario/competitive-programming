#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// #define endl '\n'
#define double long double
#define int long long

const int N = 1e5 + 5;

int n, k;
ld p[N];

ld f(int tam){
    vector<ld> dp(2 * n + 1, 0);
    dp[n] = 1;
    for(int i = n - tam; i < n; i++) {
        vector<ld> tmp(2 * n + 1, 0);
        for(int j = 0; j < dp.size(); j++) {
            if(j != 2 * n) {
                tmp[j] += dp[j + 1] * (1 - p[i]);
            }
            if(j != 0) {
                tmp[j] += dp[j - 1] * p[i];
            }
        }
        dp = tmp;
    }
    ld prob = 0;
    for(int i = n + k; i < 2 * n + 1; i++) {
        prob += dp[i];
    }
    return prob;
}

ld ternary_search(ll l, ll r){
    while(r - l > 3){
        ll m1 = (l + r)/2;
        ll m2 = (l + r)/2 + 1;
        ll f1 = f(m1), f2 = f(m2);
        if(f1 < f2) l = m1;
        else r = m2;
    }
    ld ans = 0;
    for(int i = l; i <= r; i++){
        ld tmp = f(i);
        ans = max(ans, tmp);
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    int l = 1, r = n;
    cout << setprecision(20) << fixed << ternary_search(l, r) << "\n";
}