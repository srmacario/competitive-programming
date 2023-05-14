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

int t,n,st[4*N], v[N], nxt[N], d[N];

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
    if (l != r) st[p] = max(st[2*p], st[2*p+1]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        build(1,0,n);
        stack<pii> s;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            while(s.size()){
                pii cur = s.top();
                if(cur.st < v[i]) nxt[cur.nd] = i;
                else break;
                s.pop(); 
            }
            s.push({v[i],i});
        }
        update(1,0,n,0,1);
        nxt[0] = 1;
        priority_queue <pii> pq;
        pq.push({-nxt[0],0});
        for(int i=1;i<=n;i++){
            int mx = query(1,0,n,0,v[i]);
            //cout << mx+1 << " ";
            update(1,0,n,v[i],mx+1);
            int last = -1;
            while(pq.size()){
                pii cur = pq.top();
                if(-cur.st == i) {
                    if(last != cur.nd){
                        int now = query(1,0,n,cur.nd,cur.nd);
                        update(1,0,n,cur.nd,now+1);
                    }
                }
                else break;
                pq.pop();
                last = cur.nd;
            }
            if(nxt[i]) pq.push({-nxt[i],v[i]});
        }
        cout << query(1,0,n,0,n) - 1 << "\n";
        for(int i=0;i<=n;i++) v[i] = nxt[i] = 0;
    }
    return 0;
}