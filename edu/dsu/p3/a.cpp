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
const int N = 2e5+5;

int n, m;

int par[N], sz[N], cnt;
vi check;
stack <pii> sp, ss;

int find (int a) { return par[a] == a ? a : find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    ss.push({a, sz[a]});
    sp.push({b, par[b]});
    sz[a] += sz[b];
    par[b] = a;
    cnt--;
}

void rollback() {
    par[sp.top().st] = sp.top().nd; sp.pop();
    sz[ss.top().st]  = ss.top().nd; ss.pop();
    cnt++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    cin >> n >> m;
    cnt = n;
    for(int i = 0; i < m; i++){
        string s;
        int u, v;
        cin >> s;
        if(s == "persist"){
            check.pb(sp.size());
        }
        if(s == "union"){
            cin >> u >> v;
            unite(u, v);
            cout << cnt << "\n";
        }
        if(s == "rollback"){
            while(sp.size() > check.back()) rollback();
            check.pop_back();
            cout << cnt << "\n";
        }
    }
    return 0;
}