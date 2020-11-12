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

const int N = 1e3+5;

int vis[2*N], ord[2*N], ordn, cnt, cmp[2*N], val[N], n;
vector <int> adj[2*N], adjt[2*N];

int v (int x) { return 2*x; }
int nv (int x) { return 2*x+1; }

void add (int p, int q) {
    adj[p].push_back(q);
    adj[q^1].push_back(p^1);
    adjt[q].push_back(p);
    adjt[p^1].push_back(q^1);
}

void dfs (int x) {
    vis[x] = 1;
    for (auto v : adj[x]) if (!vis[v]) dfs(v);
    ord[ordn++] = x;
}

void dfst (int x) {
    cmp[x] = cnt, vis[x] = 0;
    for(auto v : adjt[x]) if (vis[v]) dfst(v);
}

bool run2sat() {
    for (int i = 1; i <= n; i++) {
        if (!vis[v(i)]) dfs(v(i));
        if (!vis[nv(i)]) dfs(nv(i));
    }
    for (int i = ordn-1; i >= 0; i--)
        if (vis[ord[i]]) cnt++, dfst(ord[i]);
    for (int i = 1; i <= n; i++) {
        if (cmp[v(i)] == cmp[nv(i)]) return false;
        val[i] = cmp[v(i)] > cmp[nv(i)];
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k=1;k<=t;k++){
        for(int i=0;i<2*N;i++){
            adj[i].clear();
            adjt[i].clear();
            vis[i] = 0;
            ord[i] = 0;
            cmp[i] = 0;
            val[i] = 0;
            cnt = 0;
            ordn = 0;
        }
        cin >> n;
        string ans;
        vector <pii> task;
        for(int i=0;i<n;i++){
            int x,y;
            cin >> x >> y;
            task.pb({x,y});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(task[i].st >= task[j].nd){
                    continue;
                }
                if(task[i].nd <= task[j].st){
                    continue;
                }
                add(v(i+1),nv(j+1));
                add(nv(j+1),v(i+1));
            }
        }
        bool ok = run2sat();
        if(!ok) ans = "IMPOSSIBLE";
        else{
            for (int i = 1; i <= n; i++) {
                if (val[i]) ans+="J"; 
                else ans+="C";
            }
        }
        cout << "Case #" << k << ": " << ans << "\n";
    }
    return 0;
}