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

int st[4*N], v[N];

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = max(st[2*p], st[2*p+1]);
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return -INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {st[p] = v; return;}
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    st[p] = max(st[2*p], st[2*p+1]);
}

struct maxQueue {
    deque <ll> d;
    queue <ll> q;

    void init () {
        while (d.size()) d.pop_front();
        while (q.size()) q.pop();
    }

    void push (ll x) {
        q.push(x);
        while (d.size() and d.back() < x) d.pop_back();
        //                  d.back() > x   <---  if min queue
        d.push_back(x);
    }

    void pop () {
        if (q.size() and q.front() == d.front()) d.pop_front();
        q.pop();
    }

    ll maxi () {
        if (!d.size()) return LINF;
        return d.front();
    }
};

int a[N], dp[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l,r;
    cin >> n >> l >> r;
    for(int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    dp[l] = query(1,1,n,1,l);
    maxQueue mq;
    for(int i=l;i<=n;i++){
        
        for(int j = max(l,i-r);j<i-l+1;j++){
            int cur = min(dp[j],query(1,1,n,j+1,i));
        }
    }
    return 0;
}