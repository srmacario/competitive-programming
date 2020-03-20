#include <bits/stdc++.h>
#define ll long long
#define pb push_back
const int N = 1e3+5;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, anst = 0,ansb = 0;
    vector<ll> c;
    cin >> n;
    for(int i=0;i<n;i++){
        ll s,x;
        cin >> s;
        for(int j=0;j<s/2;j++){
            cin >> x;
            anst+=x;
        }
        if(s%2){
            cin >> x;
            c.pb(x);
        }
        for(int j=0;j<s/2;j++){
            cin >> x;
            ansb+=x;
        }
        }
    sort(c.begin(),c.end(),greater<ll>());
    for(int i=0;i<c.size();i++){
        if(i%2) ansb+=c[i];
        else anst+=c[i];
    }
    cout << anst << " " << ansb << "\n";
    return 0;
}