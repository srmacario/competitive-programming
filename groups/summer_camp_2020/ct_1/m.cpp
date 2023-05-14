#include <bits/stdc++.h>

#define ll long long
const int N = 1e5;

using namespace std;

ll a[N], ps[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, maxsofar = 0, maxnow = 0;
    cin >> n >> x;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        ps[i] = a[i] - a[i-1];
    }
    for(ll i=2;i<=n;i++){
        if(ps[i] <= x) maxnow++, maxsofar = max(maxsofar,maxnow);
        else maxnow = 0;
    }
    cout << ++maxsofar << "\n";
    return 0;
}
