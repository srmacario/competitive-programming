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

int n, h, l;
vector<int> adj[N];
int dist[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> h >> l;
    vector<int> horror;
    for(int i = 0; i < h; i++){
        int x;
        cin >> x;
        horror.push_back(x);
    }
    for(int i = 0; i < l; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) dist[i] = INF;
    queue<int> q;
    for(auto x : horror) q.push(x), dist[x] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(dist[u] + 1 < dist[v]){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    pii ans = {-INF, -INF};
    for(int i = n - 1; i >= 0; i--) ans = max(ans, make_pair(dist[i], -i));
    cout << -ans.nd << "\n";
    return 0;
}