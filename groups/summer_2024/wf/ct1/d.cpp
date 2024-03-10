//Слава Україні, Героям слава
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 707, K = 1024;
 
unordered_map<int, bool> dp, vis;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < N; i++) {
        dp[(i << 20) + (i << 10) + i] = true;
    }
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    function<void(int, int, int)> calc = [&](int l, int r, int c) {
        if(l == r) {
            return;
        }
        if(vis[(l << 20) + (r << 10) + c]) return;
        vis[(l << 20) + (r << 10) + c] = true;
        for(int i = l; i < c; i++) {
            if(__gcd(v[i], v[c]) != 1) {
                calc(l, c - 1, i);
                dp[(l << 20) + (r << 10) + c] |= dp[(l << 20) + ((c - 1) << 10) + i];
            }
        }
        for(int i = c + 1; i <= r; i++) {
            if(__gcd(v[i], v[c]) != 1) {
                calc(c + 1, r, i);
                dp[(l << 20) + (r << 10) + c] |= dp[((c + 1) << 20) + (r << 10) + i];
            }
        }
    };
    for(int i = 1; i <= n; i++) {
        calc(1, n, i);
    }
    bool foi = false;
    for(int i = 1; i <= n; i++) {
        foi |= dp[(1 << 20) + (n << 10) + i];
    }
    cout << (foi ? "YES\n" : "NO\n");
    return 0;
}