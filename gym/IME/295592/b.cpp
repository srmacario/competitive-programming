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
const int N = 105;

map<int,string> m;
vector<piii> f;
vi adj[N];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    f.pb({0,{0,0}});
    for(int i=1;i<=n;i++){
        string s;
        int hp, at, df;
        cin >> s >> hp >> at >> df;
        m[i] = s;
        f.pb({hp,{at,df}});
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll A = max(0,(f[j].nd.st - f[i].nd.nd)), B = max(0,(f[i].nd.st - f[j].nd.nd));
            ll na, nb;
            if(A == 0) na = INF;
            else{
                na = ((f[i].st - 1)/ A) + 1;
            }
            if(B == 0) nb = INF;
            else{
                nb = ((f[j].st - 1)/ B) + 1;
            }
            if(na < nb) adj[j].pb(i);
            else if(na > nb) adj[i].pb(j);
        }
    }
    set <piii> ans;
    for(int i=1;i<=n;i++){
        for(auto u : adj[i]){
            for(auto v : adj[u]){
                for(auto x : adj[v]){
                    if(x == i){
                        ll a,b,c;
                        a = min({i,u,v});
                        c = max({i,u,v});
                        if(i != a and i != c) b = i;
                        if(u != a and u != c) b = u;
                        if(v != a and v != c) b = v;
                        ans.insert({a,{b,c}});
                    }
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto u : ans) cout << m[u.st] << " " << m[u.nd.st] << " " << m[u.nd.nd] << "\n";
    return 0;
}