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

int par[N], dist[N], dist2[N];
vi adj[N];
pii ini[N], fim[N], mn[N];
set <int> all,src;

void dfs(int s, int cnt){
    par[s] = cnt;
    for(auto v:adj[s]){
        if(!par[v]) dfs(v,cnt);
    }
}

void bfs(){
    cl(dist,63);
    queue <int> q;
    for(auto s : src){
        dist[s] = 0;
        q.push(s);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    //dfs para marcar cada arvore com um id: o id será par[i]
    for(int i=1;i<=n;i++){
        if(!par[i]){
            dfs(i,i);
        }
    }
    //insere todos os ids num set all e num set src (para usar o bfs)
    for(int i=1;i<=n;i++) all.insert(par[i]), src.insert(par[i]);
    //bfs a partir de todas as srcs
    bfs();
    for(int i=1;i<=n;i++){
        ini[par[i]] = max({{dist[i],i},ini[par[i]]});
    }
    src.clear();
    for(auto p : all) src.insert(ini[p].nd);
    bfs();
    for(int i=1;i<=n;i++){
        dist2[i] = dist[i];
        fim[par[i]] = max({{dist[i],i},fim[par[i]]});
    }
    src.clear();
    for(auto p : all) src.insert(fim[p].nd);
    bfs();
    cl(mn,63);
    for(int i=1;i<=n;i++){
        int d = max(dist2[i],dist[i]);
        mn[par[i]] = min({mn[par[i]],{d,i}});
    }
    vector<pii> ans;
    for(auto p : all){
        mn[p].st = (fim[p].st+1)/2;
        ans.pb(mn[p]);
    }
    sort(ans.begin(),ans.end());
    if(ans.size() == 1) cout << fim[par[1]].st << "\n";
    else{
        int tot = ans[ans.size()-1].st + ans[ans.size()-2].st + 1;
        if(ans.size() > 2){
            if(ans[ans.size()-1].st == ans[ans.size()-2].st and ans[ans.size()-1].st == ans[ans.size()-3].st) tot++;
        }
        for(int i=1;i<=n;i++){
            tot = max(tot,fim[par[i]].st);
        }
        cout << tot << "\n";
        for(int i=0;i<ans.size()-1;i++){
            cout << ans[i].nd << " " << ans.back().nd << "\n";
        }
    }
    return 0;
}