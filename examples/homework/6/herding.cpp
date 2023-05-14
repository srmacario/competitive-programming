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
const int N = 1e6+5;

int vis[N], n, m, adj[N], cnt, cur;

int id(int i, int j){
    return i*m + j;
}

void connect(int pos, char c){
    if(c == 'N') adj[pos] = pos-m;
    if(c == 'S') adj[pos] = pos+m;
    if(c == 'W') adj[pos] = pos-1;
    if(c == 'E') adj[pos] = pos+1;
}

int dfs(int s, int t){
    vis[s] = t;
    if(!vis[adj[s]]){
        return dfs(adj[s], t);
    }
    else if(vis[adj[s]] == t) return 1;
    return 0;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            scanf(" %c", &c);
            connect(id(i,j), c);
        }
    }
    for(int i = 0; i < n*m; i++){
        if(!vis[i]){
            int go = dfs(i, ++cur);
            cnt += go;
        }
    }
    printf("%d\n", cnt);
    return 0;
}