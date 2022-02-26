#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

int n, k, t, h[N], sub[N];
vi adj[N],verts;

void dfs(int s){
    h[s]++;
    sub[s] = 1;
    for(auto v: adj[s]) if(!h[v]){
        h[v] = h[s];
        dfs(v);
        sub[s] += sub[v];
    }
}

bool cmp(int a, int b){
    return h[a] - sub[a] > h[b] - sub[b];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++) verts.pb(i);
    sort(verts.begin(),verts.end(),cmp);
    ll ans = 0;
    for(int i=0;i<k;i++){
        ans += h[verts[i]] - sub[verts[i]];
    }
    cout << ans << "\n";
    return 0;
}