#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 205;

int t[N], kid[N][N];

int n, ordn, cnt, val[N], vis[2*N], ord[2*N], cmp[2*N];
vector<int> adj[2*N], adjt[2*N];

// for a variable u with idx i
// u is 2*i and !u is 2*i+1
// (a v b) == !a -> b ^ !b -> a

int v(int x) { return 2*x; }
int nv(int x) { return 2*x+1; }

void clear(){
    ordn = cnt = 0;
    memset(val, 0, sizeof(val));
    memset(vis, 0, sizeof(vis));
    memset(ord, 0, sizeof(ord));
    memset(cmp, 0, sizeof(cmp));
    for(int i = 0; i < 2 * N; i++){
        adj[i].clear(), adjt[i].clear();
    }
}

// add clause (a v b)
void add(int a, int b){
    adj[a^1].push_back(b);
    adj[b^1].push_back(a);
    adjt[b].push_back(a^1);
    adjt[a].push_back(b^1);
}

void dfs(int x){
    vis[x] = 1;
    for(auto v : adj[x]) if(!vis[v]) dfs(v);
    ord[ordn++] = x;
}

void dfst(int x){
    cmp[x] = cnt, vis[x] = 0;
    for(auto v : adjt[x]) if(vis[v]) dfst(v);
}

bool run2sat(){
    for(int i = 1; i <= n; i++) {
        if(!vis[v(i)]) dfs(v(i));
        if(!vis[nv(i)]) dfs(nv(i));
    }
    for(int i = ordn-1; i >= 0; i--) 
    if(vis[ord[i]]) cnt++, dfst(ord[i]);
    for(int i = 1; i <= n; i ++){
        if(cmp[v(i)] == cmp[nv(i)]) return false;
        val[i] = cmp[v(i)] > cmp[nv(i)];
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        for(int j = 1; j <= n - 1; j++) cin >> kid[i][j];
    }
    for(int k = 0; k < n; k++){
        clear();
        for(int i = 1; i <= n; i++){
            for(int j = k + 1; j <= n - 1; j++){
                //add clauses
                // db(i _ kid[i][j] _ (t[i] == t[kid[i][j]]));
                if(t[i] != t[kid[i][j]]){
                    //~i => ~j := i v ~j
                    if((t[i] + 1) % 3 == (t[kid[i][j]] + 2) % 3)
                        add(v(i), nv(kid[i][j]));
                    //i => j := ~i v j
                    if((t[i] + 2) % 3 == (t[kid[i][j]] + 1) % 3)
                        add(nv(i), v(kid[i][j]));
                }
                else{
                    //i => ~j := ~i v ~j
                    //~i => j := i v j
                    add(v(i), v(kid[i][j]));
                    add(nv(i), nv(kid[i][j]));
                }
            }
        }
        bool ok = run2sat();
        if(ok){
            cout << k << "\n";
            return 0;
        }
    }
    cout << n - 1 << "\n";
    return 0;
}