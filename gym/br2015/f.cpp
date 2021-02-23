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
typedef pair<double,int>pdi;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-6, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int N = 1e3+5;

typedef double type;

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

int n,m;
double dist[N];
vector <piii> adj[N];

double dijkstra(double t){
    for(int i=1;i<=n;i++) dist[i] = (double)INF;
    priority_queue<pdi> pq;
    dist[1] = 0.0;
    pq.push({0.0, 1});

    while (!pq.empty()) {
        double ud = -pq.top().st;
        int u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            int v = x.st;
            int a = x.nd.st;
            int b = x.nd.nd;
            double w = a * t + b;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
    return dist[n];
}

double ternary_search(double l, double r){
    for(int i=0;i<200;i++){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (dijkstra(m1) < dijkstra(m2))
            l = m1;
        else
            r = m2;
    }
    return dijkstra(l);  
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,a,b;
        scanf("%d%d%d%d",&u,&v,&a,&b);
        adj[u].pb({v,{a,b}});
        adj[v].pb({u,{a,b}});
    }
    double ans = ternary_search(0.0,1440.0);
    printf("%.5lf\n",ans);
    return 0;
}