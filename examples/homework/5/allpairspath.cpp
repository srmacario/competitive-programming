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
const int N = 200;

int dist[N][N], tmpdist[N];
vector<pii> adj[N];
int n, m, q;

void bellman(){
    for(int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int u = 0; u < n; u++){
                for (auto x : adj[u]) {
                    int v = x.st;
                    int w = x.nd;
                    if(dist[k][u] < INF)
                    dist[k][v] = min(dist[k][v], dist[k][u] + w);
                }
            }
        }
        for(int i = 0; i < n; i++){
            tmpdist[i] = dist[k][i];
        }
        for (int i = 0; i < n; i++){
            for (int u = 0; u < n; u++){
                for (auto x : adj[u]) {
                    int v = x.st;
                    int w = x.nd;
                    if(dist[k][u] < INF)
                    dist[k][v] = min(dist[k][v], dist[k][u] + w);
                }
            }
        }
        for(int i = 0; i < n; i++) if(tmpdist[i] != dist[k][i]) dist[k][i] = -INF;
    }
}

void floyd(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(dist[i][k] < INF and dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if(dist[i][k] < INF and dist[k][j] < INF and dist[k][k] < 0)
                    dist[i][j] = -INF;
}

int main(){
    while(1){
        scanf("%d%d%d", &n, &m, &q);
        if(n == 0 and m == 0 and q == 0) break;
        cl(dist,63);
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(int i = 0; i < m ; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            //adj[u].pb({v,w});
            dist[u][v] = min(w,dist[u][v]);
        }
        //bellman();
        floyd();
        for(int i = 0; i < q; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            if(dist[u][v] == -INF) printf("-Infinity\n");
            else if(dist[u][v] == INF) printf("Impossible\n");
            else printf("%d\n", dist[u][v]);
        }
        for(int i = 0;i < n;i++) adj[i].clear();
        printf("\n");
    }
    return 0;
}