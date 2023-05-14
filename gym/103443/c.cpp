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
const int N = 2e5+5, M = 1e6 + 5;

int n, e, cnt;
int l[N], r[N], del[N];
string name[N];

vector<int> st[4*M], lazy[4*M];

void repush(int p){
    while(del[st[p].back()]) st[p].pop_back();
}

void push (int p, int l, int r) {
    if (lazy[p].size()) {
        for(auto top : lazy[p]) st[p].push_back(top);
        // RMQ (max/min)   -> update: = lazy[p],         incr: += lazy[p]
        // RSQ (sum)       -> update: = (r-l+1)*lazy[p], incr: += (r-l+1)*lazy[p]
        // Count lights on -> flip:   = (r-l+1)-st[p];
        if (l != r) {
            for(auto top : lazy[p]) lazy[2*p].push_back(top);
            for(auto top : lazy[p]) lazy[2*p+1].push_back(top);
            // update:    lazy[2*p] = lazy[p],  lazy[2*p+1] = lazy[p];
            // increment: lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
            // flip:      lazy[2*p] ^= 1,       lazy[2*p+1] ^= 1;
        }
        lazy[p].clear();
    }
}

int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    repush(p);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p].back();
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    repush(p);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p].push_back(k);
        // update:    lazy[p] = k;
        // increment: lazy[p] += k;
        // flip:      lazy[p] = 1;
        push(p, l, r);
        repush(p);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    // st[p]pu = max(st[2*p].back(), st[2*p+1].back());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> e;
    for(int i = 0; i < 4 * M; i++) st[i].push_back(0);
    for(int i = 0; i < e; i++){
        int op, c, d;
        cin >> op;
        if(op == 1){
            cin >> name[++cnt] >> l[cnt] >> r[cnt];
            update(1, 1, n, l[cnt], r[cnt], cnt);
        }
        else{
            cin >> c >> d;
            int ans = query(1, 1, n, c, d);
            if(ans){
                cout << name[ans] << "\n";
                del[ans] = 1;
            }
            else{
                cout << ">_<\n";
            }
        }
    }
    return 0;
}