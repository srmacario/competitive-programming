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
const int N = 1e5+5;

int n,m,cnt,par[N];
vi adj[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        par[y]++;
        adj[x].pb(y);
    }
    vector<int> ans;
    priority_queue<int> q;
    for(int i=1;i<=n;i++) if(!par[i]) q.push(-i);
    while(q.size()){
        int u = -(q.top());
        q.pop();
        cnt++, ans.pb(u);
        for(auto v : adj[u]){
            par[v]--;
            if(!par[v]) q.push(-v);
        }
    }
    if(cnt == n){
        for(int i=0;i<n;i++) cout << ans[i] << " ";
       cout << "\n";
    }
    else cout << "Sandro fails.\n";
    return 0;
}