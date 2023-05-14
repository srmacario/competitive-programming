#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, vis[2*N], ord[2*N], ordn, cnt, cmp[2*N], val[N];
vi adj[2*N], adjt[2*N];

int v(int x) {return 2*x;}
int nv(int x) {return 2*x + 1;}

void add(int a, int b){
    adj[a^1].push_back(b);
    adj[b^1].push_back(a);
    adjt[b].push_back(a^1);
    adjt[a].push_back(b^1);
}

void dfs(int x){
    vis[x] = 1;
    for(auto v: adj[x]) if(!vis[v]) dfs(v);
    ord[ordn++] = x;
}

void dfst(int x){
    cmp[x] = cnt, vis[x] = 0;
    for(auto v: adjt[x]) if(vis[v]) dfst(v);
}

bool run2sat(){
    for(int i=1; i<=n; i++){
        if(!vis[v(i)]) dfs(v(i));
        if(!vis[nv(i)]) dfs(nv(i));
    }
    for(int i = ordn-1; i>=0; i--)
        if(vis[ord[i]]) cnt++, dfst(ord[i]);
    for(int i=1;i<=n;i++){
        if(cmp[v(i)] == cmp[nv(i)]) return false;
        val[i] = cmp[v(i)] > cmp[nv(i)];
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> n >> k;
    for(int i = 0;i<k;i++){
        char l1,l2,l3;
        int a,b,c,av,anv,bv,bnv,cv,cnv;
        cin >> a >> l1 >> b >> l2 >> c >> l3;
        if(l1 == 'R') av = v(a), anv = nv(a); else av = nv(a), anv = v(a);
        if(l2 == 'R') bv = v(b), bnv = nv(b); else bv = nv(b), bnv = v(b);
        if(l3 == 'R') cv = v(c), cnv = nv(c); else cv = nv(c), cnv = v(c);
        add(av,bv), add(av,cv);
        add(bv,av), add(bv,cv);
        add(cv,av), add(cv,bv);
    }
    bool ok = run2sat();
    if(!ok) cout << "-1";
    else{
        for(int i=1;i<=n;i++) cout << (val[i] ? 'R' : 'B');
    }
    cout << "\n";
    return 0;
}