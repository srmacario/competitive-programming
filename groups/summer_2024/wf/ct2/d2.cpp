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
const int N = 1e5+5, M = 5000;


int x, marcB[N], matchB[N], matchA[N], ans, n, m, d, k[N], p[N], c[N];
vector<int> adj[N], waiting_adj[N];

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

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    cin >> d;
    set<int> removed;
    for(int i = 1; i <= d; i++){
        cin >> k[i];
        removed.insert(k[i]);
    }

    for(int i = 1; i <= n; i++){
        if(removed.count(i)) continue;
        if(p[i]){
            waiting_adj[p[i]].push_back(i);
            continue;
        }
        adj[p[i]].push_back(c[i] + 2 * M);
        adj[c[i] + 2 * M].push_back(p[i]);
    }

    for(int i = 0; i <= M; i++) matchA[i] = -1;
    for(int j = 2 * M + 1; j <= 2 * M + M; j++) matchB[j] = -1;

    vector<int> resp;
    for(int i = d; i >= 1; i--){

        bool aux = true;
        while(aux){
            for(int j = 2 * M + 1; j <= 2 * M + M; j++) marcB[j] = 0;
            aux = false;
            for(int j = 0; j <= n; j++){
                if(matchA[j] != -1) continue;
                if(dfs(j)){
                    // db(j);
                    ans++;
                    for(auto w : waiting_adj[ans]){
                        adj[p[w]].push_back(c[w] + 2 * M);
                        adj[c[w] + 2 * M].push_back(p[w]);
                    }
                    aux = true;
                }
            }
        }
        resp.push_back(ans);
        if(p[k[i]] <= ans){
            adj[p[k[i]]].push_back(c[k[i]] + 2 * M);
            adj[c[k[i]] + 2 * M].push_back(p[k[i]]);
        }
        else waiting_adj[p[k[i]]].push_back(k[i]);
    }
    reverse(resp.begin(), resp.end());
    for(int i = 0; i < d; i++) cout << resp[i] << "\n";
    return 0;
}