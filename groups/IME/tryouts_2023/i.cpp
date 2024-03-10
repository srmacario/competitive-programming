#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        a[k]++;
    }
    ll ans = 0;
    for(ll i = 1; i*i <= x; i++){
        if(x % i) continue;
        ll j = x/i;
        if(i == j) ans += (a[i] * (a[i] - 1)) / 2;
        else ans += (a[i] * a[j]);
    }
    cout << ans << "\n";
    return 0;
}