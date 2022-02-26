#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9+7;

ll fexp(ll b, ll e, ll m = MOD){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e /= 2;
    }
    return ans;
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << fexp(a,b) << "\n";
}