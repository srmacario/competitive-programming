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
const int N = 3e5+5;

vi adj[N], mark, sz, cur;

bool cmp(int a, int b){
    return sz[a] - cur[a] < sz[b] - cur[b];
}

void dfs(int s){
    mark[s] = 1;
    for(auto v: adj[s]){
        cur[v]++;
    }
    sort(adj[s].begin(), adj[s].end(), cmp);
    for(auto v: adj[s]){
        if(cur[v] >= (sz[v]+1)/2){
            if(!mark[v]) dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,p,x,l;
    cin >> c >> p >> x >> l;
    mark.pb(0), sz.pb(0), cur.pb(0);
    for(int i=1;i<=c;i++) mark.pb(i == l ? 1 : 0);
    for(int i=0;i<p;i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=c;i++) sz.pb(adj[i].size()), cur.pb(0);
    dfs(l);
    cout << (mark[x] ? "leave" : "stay") << "\n";
    return 0;
}