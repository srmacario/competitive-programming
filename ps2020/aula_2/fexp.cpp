#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9+7;

ll fexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b%2) ans = ans*a % MOD;
        a = a*a % MOD;
        b /= 2;
    }
    return ans;
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << fexp(b,e);
}