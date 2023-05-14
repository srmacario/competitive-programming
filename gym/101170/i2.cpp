#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, m[2];
ll dist_bfs[N][3];
vi adj[N], adjt[N];
vector<int> item[2];

void bfs(vector<int> u, int idx, bool is_reverse){
    for (int i = 1; i <= n; i++) dist_bfs[i][idx] = INF;
    queue<int> q;
    for (auto x : u) {
        dist_bfs[x][idx] = 0;
        q.push(x);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if (is_reverse) {
            for(auto v: adjt[u]){
                if(dist_bfs[v][idx] > dist_bfs[u][idx] + 1){
                    dist_bfs[v][idx] = dist_bfs[u][idx] + 1;
                    q.push(v);
                 }
            }
        } else {
            for(auto v: adj[u]){
                if(dist_bfs[v][idx] > dist_bfs[u][idx] + 1){
                    dist_bfs[v][idx] = dist_bfs[u][idx] + 1;
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m[0] >> m[1];
    
    for(int i = 0; i < 2; i++){
        item[i].resize(m[i]);
        for(int j = 0; j < m[i]; j++) cin >> item[i][j];
    }
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        for(int k = 0; k < a; k++){
            int j;
            cin >> j;
            adj[i].pb(j);
            adjt[j].pb(i);
        }
    }

    bfs({ 1 }, 0, false);
    bfs(item[0], 1, true);
    bfs(item[1], 2, true);
    
    ll ans = INF;
    for (int i = 1; i <= n; i++) ans = min(ans, dist_bfs[i][0] + dist_bfs[i][1] + dist_bfs[i][2]);

    if (ans == INF) cout << "impossible\n";
    else cout << ans << "\n";
    return 0;
}
