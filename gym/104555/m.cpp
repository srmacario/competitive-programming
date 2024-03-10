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
const int N = 105;

int n, adj[N][N], dist[N][N], par[N][N];

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == k or j == k) continue;
                if((dist[i][j] >= dist[i][k] + dist[k][j])){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    par[i][j] = k;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> adj[i][j];
            par[i][j] = i;
            dist[i][j] = adj[i][j];
        }
    }
    floyd();
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(adj[i][j] != dist[i][j]){
                cout << "-1\n";
                return 0;
            }
            if(par[i][j] != i) ans++;
        }
    }
    cout << ans/2 << "\n";
    return 0;
}