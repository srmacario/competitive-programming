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
const int N = 5e5+5;

int n, q, cnt, l[N], r[N], c[N], bit[N], vis[N], ans[N];
vi pos[N];

void add (int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

int query (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int rangesum (int a, int b) {
    return query(b)-(a ? query(a-1) : 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<=q;i++){
        cin >> l[i] >> r[i];
        pos[r[i]].pb(i);
    }
    for(int i=1;i<=n;i++) vis[i] = -1;
    for(int i=1;i<=n;i++){
        if(vis[c[i]] != -1){
            add(vis[c[i]],-1);
        }
        vis[c[i]] = i;
        add(i,1);
        while(pos[i].size()){
            int cur = pos[i].back();
            ans[cur] = rangesum(l[cur],r[cur]);
            pos[i].pop_back();
        }
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
    return 0;
}