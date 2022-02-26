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

int v[N], n, pos[N], h[N];
vi adj[N];

int query (int i, int j) {
    int mx = 0;
    while (i <= j){
        mx = max(v[i], mx);
        i++;
    }
    return mx;
}

int dfs(int l, int r, int cnt){
    int mx = query(l,r);
    int m = pos[mx];
    h[m] = cnt;
    if(m != l){
        adj[m].pb(query(l,m-1));
        dfs(l,m-1,cnt+1);
    }
    if(m != r){
        adj[m].pb(query(m+1,r));
        dfs(m+1,r,cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            pos[v[i]] = i;
        }
        dfs(0, n-1, 0);
        for(int i=0;i<n;i++) cout << h[i] << " ";
        cout << "\n";
        for(int i=0;i<n;i++) adj[i].clear();
        memset(v,0,sizeof(v));
    }
    return 0;
}