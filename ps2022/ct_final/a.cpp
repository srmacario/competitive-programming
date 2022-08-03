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
const int M = 2e5+5;

int m, cnt, ing[M];
vector<int> adj[M];
string revid[M];
map<string, int> id;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    for(int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        if(!id.count(a)) id[a] = ++cnt;
        if(!id.count(b)) id[b] = ++cnt;
        ing[id[b]]++;
        adj[id[a]].push_back(id[b]);
    }
    queue<int> q;
    int processed = 0;
    for(int i = 1; i <= cnt; i++) if(!ing[i]) q.push(i);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        processed++;
        for(auto v: adj[u]){
            if(!(--ing[v])){
                q.push(v);
            }
        }
    }
    if(processed == cnt) cout << "I disagree with the advisor\n";
    else cout << "No more comedians++\n";
    return 0;
}