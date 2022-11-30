#include <bits/stdc++.h>

using namespace std;

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
const int N = 3e5+5;

int n, m, id[2][N], pos[2][N];
int st[2][4*N], v[2][N], lazy[2][4*N];
set<int> all, tog[2][2];

void build (int s, int p, int l, int r) {
    lazy[s][p] = 0;
    if (l == r) {st[s][p] = v[s][l]; return;}
    build (s, 2*p, l, (l+r)/2);
    build (s, 2*p+1, (l+r)/2+1, r);
    st[s][p] = max(st[s][2*p], st[s][2*p+1]);
}

void push (int s, int p, int l, int r) {
    if (lazy[s][p]) {
        st[s][p] += (r-l+1)*lazy[s][p];
        // RMQ (max/min)   -> update: = lazy[s][p],         incr: += lazy[s][p]
        // RSQ (sum)       -> update: = (r-l+1)*lazy[s][p], incr: += (r-l+1)*lazy[s][p]
        // Count lights on -> flip:   = (r-l+1)-st[s][p];
        if (l != r) {
            lazy[s][2*p] += lazy[s][p];
            lazy[s][2*p+1] += lazy[s][p];
            // update:    lazy[s][2*p] = lazy[s][p],  lazy[s][2*p+1] = lazy[s][p];
            // increment: lazy[s][2*p] += lazy[s][p], lazy[s][2*p+1] += lazy[s][p];
            // flip:      lazy[s][2*p] ^= 1,       lazy[s][2*p+1] ^= 1;
        }
        lazy[s][p] = 0;
    }
}

int query (int s, int p, int l, int r, int i, int j) {
    push(s, p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[s][p];
    int x = query(s, 2*p, l, (l+r)/2, i, j);
    int y = query(s, 2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void sum_update (int s, int p, int l, int r, int i, int j, int k) {
    push(s, p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[s][p] += k;
        // update:    lazy[s][p] = k;
        // increment: lazy[s][p] += k;
        // flip:      lazy[s][p] = 1;
        push(s, p, l, r);
        return;
    }
    sum_update(s, 2*p, l, (l+r)/2, i, j, k);
    sum_update(s, 2*p+1, (l+r)/2+1, r, i, j, k);
    st[s][p] = max(st[s][2*p], st[s][2*p+1]);
}

void set_update(int s, int p, int l, int r, int i, int j, int val){
    for(int k = i; k <= j; k++){
        int cur = query(s, p, l, r, k, k);
        sum_update(s, p, l, r, k, k, val - cur);
    }
}

int ub(int s, int val){
    int l = 1, r = n + 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(query(s, 1, 1, n + 1, mid, mid) <= val) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> pos[0][i] >> pos[1][i];
            id[0][pos[0][i]] = i;
            id[1][pos[1][i]] = i;
        }
        //create segs
        for(int k = 0; k < 2; k++){
            for(int i = 1; i <= n + 1; i++)
                v[k][i] = i;
            build(k, 1, 1, n + 1);
        }
        tog[0][0].insert(1), tog[1][0].insert(1);
        tog[0][1].insert(n), tog[1][1].insert(n);
        //queries
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++) db(query(0, 1, 1, n + 1, pos[0][j], pos[0][j]) _ query(1, 1, 1, n + 1, pos[1][j], pos[1][j]));
            for(int k = 0; k < 2; k++){
                cout << "tog[" << k << "][0]:\n";
                for(auto u : tog[k][0]) cout << u << " ";
                cout << "\n";
                cout << "tog[" << k << "][1]:\n";
                for(auto u : tog[k][1]) cout << u << " ";
                cout << "\n";
            }
            cout << "all:\n";
            for(auto u : all) cout << u << " ";
            cout << endl;
            char op;
            cin >> op;
            if(op == '!'){
                cout << all.size() << "\n";
            }
            else if(op == '?'){
                int k;
                cin >> k;
                cout << query(0, 1, 1, n + 1, pos[0][k], pos[0][k]) << " " << query(1, 1, 1, n + 1, pos[1][k], pos[1][k]) << "\n";
            }
            else{
                int k;
                cin >> k;
                //seg 0
                if(op == 'D'){
                    int lft = ub(0, 1), rgt = ub(0, k + 1);
                    set_update(0, 1, 1, n + 1, lft, rgt - 1, 1);
                    sum_update(0, 1, 1, n + 1, rgt, n, -k);
                    for(int j = lft; j < rgt; j++){
                        if(tog[1][0].count(j)){
                            all.insert(j);
                        }
                        else if(tog[1][1].count(j)){
                            all.insert(j);
                        }
                        tog[0][0].insert(j);
                    }
                }
                if(op == 'U'){
                    int lft = ub(1, n - k - 1), rgt = ub(1, n);
                    set_update(0, 1, 1, n + 1, lft, rgt - 1, n);
                    sum_update(0, 1, 1, n + 1, 1, lft - 1, k);
                    for(int j = lft; j < rgt; j++){
                        db(lft _ rgt);
                        if(tog[1][0].count(j)){
                            all.insert(j);
                        } else if(tog[1][1].count(j)){
                            all.insert(j);
                        }
                        tog[0][1].insert(j);
                    }
                }
                //seg 1
                if(op == 'L'){
                    int lft = ub(1, 1), rgt = ub(1, k + 1);
                    set_update(1, 1, 1, n + 1, lft, rgt - 1, 1);
                    // for(int j = 1; j <= n; j++) db(query(1, 1, 1, n + 1, j, j));
                    sum_update(1, 1, 1, n + 1, rgt, n, -k);
                    // for(int j = 1; j <= n; j++) db(query(1, 1, 1, n + 1, j, j));
                    for(int j = lft; j < rgt; j++){
                        if(tog[0][0].count(j)){
                            all.insert(j);
                        }
                        else if(tog[0][1].count(j)){
                            all.insert(j);
                        }
                        tog[1][0].insert(j);
                    }
                }
                if(op == 'R'){
                    int lft = ub(1, n - k - 1), rgt = ub(1, n);
                    set_update(1, 1, 1, n + 1, lft, rgt - 1, n);
                    sum_update(1, 1, 1, n + 1, 1, lft - 1, k);
                    for(int j = lft; j < rgt; j++){
                        if(tog[0][0].count(j)){
                            all.insert(j);
                        } else if(tog[0][1].count(i)){
                            all.insert(j);
                        }
                        tog[1][1].insert(j);
                    }
                }
            }
        }
    }
    return 0;
}