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
const int N = 3e5+5;

vi adj[N];
int dist[3][N];

void bfs(int s, int i){
    memset(dist[i],63,sizeof(dist[i]));
    dist[i][s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(dist[i][v] > dist[i][u] + 1){
                dist[i][v] = dist[i][u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pii diam = {0,0};
    bfs(1,0);
    for(int i=1;i<=n;i++) diam = max(diam,{dist[0][i],i});
    bfs(diam.nd,1);
    diam = {0,0};
    for(int i=1;i<=n;i++) diam = max(diam,{dist[1][i],i});
    bfs(diam.nd,2);
    for(int i=1;i<=n;i++){
       int d = max({diam.st,dist[1][i] + 1,dist[2][i] + 1});
       cout << d << "\n";
    }
    //cout << 3*diam.st << "\n";
    return 0;
}