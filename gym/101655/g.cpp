#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int main(){
    ll n,t,ans;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        vector<ll> v;
        v.pb(1), v.pb(1), v.pb(2), v.pb(4);
        for(int i=4;i<=n;i++){
            v.pb(v[i-1] + v[i-2] + v[i-3] + v[i-4]);
        }
        cout << v[n] << "\n";
    }
    return 0;
}
