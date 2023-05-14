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
const int N = 2e3+5;

typedef long long type;

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

int n, vis[N];
ld w, h, x[N], y[N];
vi adj[N];
//esq = n+1
//dir = n+2
//baixo = n+3
//cima = n+4

bool check(ld r){
    for(int i = 1; i <= n+4; i++) vis[i] = 0, adj[i].clear();
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            ld dist = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
            if(dist <= 4*r*r){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
        // db(x[i] _ y[i] _ r);
        //esq
        //x[i] <= r
        if(x[i] <= r){
            adj[i].pb(n+1);
            adj[n+1].pb(i);
            // db(x[i] _ r);
        }
        //dir
        //x[i] + r >= w
        if(x[i] >= w - r){
            adj[i].pb(n+2);
            adj[n+2].pb(i);
            // db(x[i] _ r _ w);
        }
        //baixo
        //y[i] <= r
        if(y[i] <= r){
            adj[i].pb(n+4);
            adj[n+4].pb(i);
            // db(y[i] _ r);
        }
        //cima
        //y[i] + r >= h
        if(y[i] + r >= h){
            adj[i].pb(n+3);
            adj[n+3].pb(i);
            // db(y[i] _ r _ h);
       }
    }
    queue <int> q;
    vis[n+1] = 1, vis[n + 3] = 1;
    q.push(n+1), q.push(n + 3);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    if(!vis[n + 2] and !vis[n + 4]) return true;
    return false;
}

ld binS(){
    ld l = 0, r = min(w, h);
    while(r - l > EPS){
        ld m = (l + r)/2.0;
        // db(m);
        if(check(m)) l = m;
        else r = m;
    }
    return l;
}

int main(){
    scanf("%Lf%Lf%d", &w, &h, &n);
    for(int i = 1; i <= n; i++){
        scanf("%Lf %Lf", &x[i], &y[i]);
    }
    cout << setprecision(10) << fixed << binS() << "\n";
    // check(1.5);
    return 0;
}