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
const int N = 1e3+5, M = 1e6+5;

ll n, m, v[N][N], sz[M], par[M], vis[M], resp[N][N], k, lft;
pll ans;

ll id(ll i, ll j){
    return i*m + j;
}

pll revid(ll num){
    return {num/m,num%m};
}

ll find (ll a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (ll a, ll b) {
    pll pos = revid(b);
    ll div = v[pos.st][pos.nd];
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] <= sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    if(!(k%div)){
        ll lft = k/div;
        if(lft <= sz[a]) ans = {lft,id(pos.st,pos.nd)};
    }
}

void dfs(ll i, ll j){
    resp[i][j] = v[revid(ans.nd).st][revid(ans.nd).nd];
    vis[id(i,j)] = 1;
    if(i > 0 and !vis[id(i-1,j)] and lft > 0 and v[i-1][j] >= v[revid(ans.nd).st][revid(ans.nd).nd]) lft--, dfs(i-1,j);
    if(j > 0 and !vis[id(i,j-1)] and lft > 0 and v[i][j-1] >= v[revid(ans.nd).st][revid(ans.nd).nd]) lft--, dfs(i,j-1);
    if(i < n and !vis[id(i+1,j)] and lft > 0 and v[i+1][j] >= v[revid(ans.nd).st][revid(ans.nd).nd]) lft--, dfs(i+1,j);
    if(j < m and !vis[id(i,j+1)] and lft > 0 and v[i][j+1] >= v[revid(ans.nd).st][revid(ans.nd).nd]) lft--, dfs(i,j+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ans = {-1,-1};
    cin >> n >> m >> k;
    priority_queue <pll> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
            pq.push({v[i][j],id(i,j)});
            par[id(i,j)] = id(i,j);
            sz[id(i,j)] = 1;
        }
    }
    while(pq.size()){
        pll cur = pq.top();
        pq.pop();
        pii pos = revid(cur.nd);
        if(k == cur.st) ans = {1,cur.nd};
        if(pos.st > 0 and v[pos.st-1][pos.nd] >= cur.st){
            unite(id(pos.st-1,pos.nd),cur.nd);
        }
        if(pos.nd > 0 and v[pos.st][pos.nd-1] >= cur.st){
            unite(id(pos.st,pos.nd-1),cur.nd);
        }
        if(pos.st < n and v[pos.st+1][pos.nd] >= cur.st){
            unite(id(pos.st+1,pos.nd),cur.nd);
        }
        if(pos.nd < m and v[pos.st][pos.nd+1] >= cur.st){
            unite(id(pos.st,pos.nd+1),cur.nd);
        }
    }
    if(ans.st == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        lft = ans.st-1;
        dfs(revid(ans.nd).st,revid(ans.nd).nd);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << resp[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}