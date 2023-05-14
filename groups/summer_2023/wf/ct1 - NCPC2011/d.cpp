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
const int N = 1e6+5;

int dist[N];
int f, s, g, u, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, 63, sizeof(dist));
    cin >> f >> s >> g >> u >> d;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        if(c + u <= f and dist[c + u] > dist[c] + 1){
            dist[c + u] = dist[c] + 1;
            q.push(c + u);
        }
        if(c - d > 0 and dist[c - d] > dist[c] + 1){
            dist[c - d] = dist[c] + 1;
            q.push(c - d);
        }
    }
    if(dist[g] == INF) cout << "use the stairs\n";
    else cout << dist[g] << "\n";
    return 0;
}