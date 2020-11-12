#include <bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define pb push_back
#define pii pair <int, int>
#define triplet <pair <pii,int>>
#define vi vector<int>
#define vii vector<vi>
#define clr(x) x.clear()
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    while(q--){
        ll n,m,ans=0;
        cin >> n >> m;
        if(m>n){
            cout << "0\n";
            continue;
        }
        if(!(m%10)) ans = 0;
        else if (!(m%5)) {
            ans = 5*(((n/m)+1)/2);
        }
        else if((m%2)){
            ans = 45*(n/(m*10));
            if((n%(10*m))){
                for(ll i = (n - n%(10*m));i<=n;i+=m){
                    ans+=i%10;
                }
            }
        }
        else if(!(m%2)){
            ans = 20*(n/(5*m));
            if((n%(5*m))){
                for(ll i = (n - n%(5*m));i<=n;i+=m){
                    ans+=i%10;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}