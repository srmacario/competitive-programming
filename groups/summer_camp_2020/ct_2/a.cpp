#include <bits/stdc++.h>
#define ll long long
const int N = 1e6+5;

using namespace std;

ll lcm(ll a, ll b){
    return (a/__gcd(a,b))*b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, c = 1;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        c = lcm(c,x);
        c = __gcd(c,k);
    }
    if(c == k) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}