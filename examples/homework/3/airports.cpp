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
const int N = 1005;

int dist[N][N], rdist[N][N];
int insp[N];
vi adj[N];
vector<piii> fl;

int x, marcB[N], matchB[N], matchA[N], ans;

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
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> insp[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin >> dist[i][j];
            if(i!=j) dist[i][j] += insp[j];
            rdist[i][j] = dist[i][j];
        }
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

    for(int i=0;i<m;i++){
        int s, f, t;
        cin >> s >> f >> t;
        fl.pb({t,{s-1,f-1}});
    }
    sort(fl.begin(),fl.end());
    for(int i = 0; i < fl.size(); i++){
        for(int j = i+1; j < fl.size(); j++){
            if(dist[fl[i].nd.nd][fl[j].nd.st] <= fl[j].st - (fl[i].st + rdist[fl[i].nd.st][fl[i].nd.nd])) adj[i].pb(j + fl.size());
        }
    }
    for(int i=0;i<N;i++) matchA[i] = matchB[i] = -1;
    bool aux = true;
    while(aux){
        for(int j=0; j<N; j++) marcB[j] = 0;
        aux = false;
        for(int i=0; i<m; i++){
            if(matchA[i] != -1) continue;
            if(dfs(i)){
                ans++;
                aux = true;
            }
        }
    }
    cout << m - ans << "\n";
    return 0;
}