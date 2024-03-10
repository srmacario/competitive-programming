//Слава Україні, Героям слава

#include <bits/stdc++.h>

using namespace std;

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
const int N = 1e5+5;

int n, m, v[N], par[N];
pair<ll, int> dist[N];
pair<ll, pii> ans;
vector<pair<int, ll>> adj[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ans = {LINF, {INF, INF}};
    cin >> n >> m;
    priority_queue<pair<ll, pii>> pq;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(v[i]) dist[i] = {0, i}, pq.push({0, {i, i}});
        else dist[i] = {LINF, INF};
    }
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    //Dijkstra
    while(!pq.empty()){
        ll ud = -pq.top().st;
        int u = pq.top().nd.st;
        int p = pq.top().nd.nd;
        pq.pop();
        if(dist[u].st < ud) continue;

        for(auto node : adj[u]){
            int v = node.st;
            ll d = node.nd;
            if(dist[v].nd != p and p != INF){
                pair<ll, pii> tmp = {dist[v].st + dist[u].st + d, {dist[v].nd, p}};
                ans = min(ans, tmp);
            }
            if(dist[v].st > dist[u].st + d){
                dist[v].st = dist[u].st + d;
                dist[v].nd = p;
                pq.push({-dist[v].st, {v, p}});
            }
        }
    }

    if(ans.st == LINF) cout << "No luck at all\n";
    else cout << ans.st << "\n" << ans.nd.st << " " << ans.nd.nd << "\n";
    return 0;
}
