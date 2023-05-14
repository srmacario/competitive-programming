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

int n, m, p[N], g[N], poss[N], can_end[N], ing[N], outg[N];
vector<int> adj[N];
ll ans[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) poss[i] = can_end[i] = 1;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        g[u]++;
    }

    for(int i = 1; i <= n; i++){
        int cur = 0;
        for(int j = 1; j <= n; j++){
            cur += poss[j];
            if(cur == g[i] + 1){
                p[i] = j, poss[j] = 0;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(p[j] > p[i]) adj[p[i]].push_back(p[j]), ing[p[j]]++, outg[p[i]]++;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) if(!ing[i]) q.push(i), ans[i] = 1;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            ing[v]--;
            if(!ing[v]){
                q.push(v);
            }
            ans[v] += ans[u];
        }
    }

    ll tot = 0;
    for(int i = 1; i <= n; i++){
        db(i _ outg[i] _ ans[i]);
        if(!outg[i]) tot += ans[i];
    }
    cout << tot << "\n";
    return 0;
}
/*

4 2
2 3
2 4

7 7
5 6
2 3
6 7
2 7
3 1
7 5
7 4

5 6
1 3
4 5
1 4
2 3
1 2
1 5
*/