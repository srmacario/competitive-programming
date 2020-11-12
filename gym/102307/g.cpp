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

int n,k,vis[N], h[N], ing[N], par[N], id[N], rev[N], ord;
vi adj[N];


bool cmp(int a, int b){

}

void dfs(int s){
    vis[s] = 1;
    for(auto v: adj[s]){
        if(!vis[v]){
            h[v] = h[s] + 1;
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        adj[x].pb(i);
    }
    dfs(0);
    sort(h,h+n+1);
    int lvl = 1, cnt = 1;
    for(int i=2;i<=n;i++){
        if(cnt == k or h[i] > lvl) lvl++, cnt = 1;
        else cnt++;
    }
    cout << lvl << "\n";
    return 0;
}