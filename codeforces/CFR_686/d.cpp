#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n;
        vector<pll> div;
        for(ll i=2;i*i<=n;i++){
            pll p = {0,i};
            while(!(n%i)){
                n/=i;
                p.st++;
            }
            if(p.st) div.pb(p);
        }
        if(n > 1) div.pb({1,n});
        sort(div.begin(),div.end(),greater<pll>());
        k = div[0].st;
        vector<ll> ans;
        for(int i=0;i<k;i++) ans.pb(div[0].nd);
        for(int i=1;i<div.size();i++){
            for(int j=0;j<div[i].st;j++) ans[k-1]*=div[i].nd;
        }
        cout << k << "\n";
        for(int i=0;i<k;i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}