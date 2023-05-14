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

int n, m, x, step[15], dist[N];
set<int> block;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, 63, sizeof(dist));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> step[i];
    cin >> m;
    for(int i = 0; i < m; i++){
        int b;
        cin >> b;
        block.insert(b);
    }
    cin >> x;
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(u + step[i] > x or block.count(u + step[i])) continue;
            if(dist[u + step[i]] > dist[u] + 1){
                dist[u + step[i]] = dist[u] + 1;
                q.push(u + step[i]);
            }
        }
    }
    if(dist[x] == INF) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}