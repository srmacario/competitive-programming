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

vi adj[N];
int marcB[N], matchA[N], matchB[N], ans, n;

bool dfs(int v){
    for(int i = 0; i < adj[v].size(); i++){
        int viz = adj[v][i];
        if(marcB[viz] == 1 ) continue;
        marcB[viz] = 1;
        if((matchB[viz] == -1) || dfs(matchB[viz])){
            matchB[viz] = v;
            matchA[v] = viz;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector <pii> al(n), tut(n);
    vector <piii> dist;
    for(int i=0;i<n;i++) cin >> al[i].st >> al[i].nd;
    for(int i=0;i<n;i++) cin >> tut[i].st >> tut[i].nd;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int d = abs(al[i].st - tut[j].st) + abs(al[i].nd - tut[j].nd);
            dist.pb({d,{i,j}});
        }
    }
    sort(dist.begin(), dist.end());
    for(int i=0;i<dist.size();i++){
        for(int k=0;k<N;k++) adj[k].clear();
        ans = 0;
        pii cur = dist[i].nd;
        for(int j=0;j<i;j++){
            pii p = dist[j].nd;
            if(p.st == cur.st or p.nd == cur.nd) continue;
            adj[p.st+1].pb(p.nd+1);
        }
        for(int j=0;j<=n;j++) matchA[j] = matchB[j] = -1;
        bool aux = true;
        while(aux){
            for(int j=1; j<=n; j++) marcB[j] = 0;
            aux = false;
            for(int i=1; i<=n; i++){
                if(matchA[i] != -1) continue;
                if(dfs(i)){
                    ans++;
                    aux = true;
                }
            }
        }
        if(ans == n-1){
            cout << dist[i].st << "\n";
            return 0;
        }
    }
    return 0;
}