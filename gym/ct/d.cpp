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
const int N = 2e5+5;

vector<pii> adj[N];
int ans[N][5], vis[N];
ll p[N];
map<pii,int> id;
map<int,pii> revid;

int dfs(int fat, int u){
    for(int i=0;i<adj[u].size();i++){
        pii v = adj[u][i];
        if(v.nd == fat) continue;
        if(!vis[id[{u,v.nd}]]){
            vis[id[{v.nd,u}]];
            dfs(v.nd,u);
        }
        int novo[5] = {0};
        for(int j=0;j<5;j++){
            novo[j] = ans[id[{fat,u}]][j];
            for(int k=0;k<5;k++){
                novo[(j+k)%5] += (ans[id[{fat,u}]][j] + ans[id[{v.nd,u}]][k]) % MOD;
                novo[k] += (ans[id[{v.nd,u}]][k]) % MOD;
            }
        }
        for(int j=0;j<5;j++){
            ans[id[{fat,u}]][j] = (novo[j] + p[id[{fat,u}]])%MOD;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int cnt = 1;
    for(int i=0;i<n-1;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        id[{a,b}] = cnt;
        p[cnt] = (c%5);
        revid[cnt++] = {a,b};
        id[{b,a}] = cnt;
        p[cnt] = (c%5);
        revid[cnt++] = {b,a};
    }
    for(int i=1;i<=2*(n-1);i++){
        if(!vis[i]){
            vis[i]++;
            dfs(revid[i].st,revid[i].nd);
            cout << ans[i][0] << " ";
        }
    }
    return 0;
}