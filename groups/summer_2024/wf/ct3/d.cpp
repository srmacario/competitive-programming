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
const int N = 2e5+5;

// Segment Tree (Range Query and Range Update)
// Update and Query - O(log n)

//Segtrees for removing positions
//i position-> 2 * i in v[0] and 2 * i - 1 in v[1]
pair<int, pll> v[2][N], st[2][4*N];
int lz[2][4*N];

pair<ll, ll> operator + (const pair<ll, ll> a, const pair<ll, ll> b){
    return {a.st + b.st, a.nd + b.nd};
}

void build(int p, int l, int r, int s = 1) {
    if (l == r) { st[s][p] = v[s][l]; return; }

    build(2*p, l, (l+r)/2, s);
    build(2*p+1, (l+r)/2+1, r, s);

    st[s][p] = min(st[s][2*p], st[s][2*p+1]);
    if(st[s][2*p].st == st[s][2*p+1].st) st[s][p].nd = st[s][2*p].nd + st[s][2*p+1].nd;
}

void push(int p, int l, int r, int s) {
    if (lz[s][p]) {
        st[s][p].st += lz[s][p];
        // RMQ -> update: = lz[s][p],         increment: += lz[s][p]
        if(l!=r){
            lz[s][2*p] += lz[s][p];
            lz[s][2*p+1] += lz[s][p];
        } // update: =, increment +=
        lz[s][p] = 0;
    }
}

pair<int, pll> query(int i, int j, int p, int l, int r, int s) {
    push(p, l, r, s);
    if(i > j) return {INF, {INF, INF}};
    if (l > j or r < i) return {INF, {INF, INF}}; // RMQ -> INF, RSQ -> 0

    if (l >= i and j >= r){
        // db(p _ s _ st[s][p].st _ st[s][p].nd);
        return st[s][p];
    }

    pair<int, pll> x = query(i, j, 2*p, l, (l+r)/2, s);
    pair<int, pll> y = query(i, j, 2*p+1, (l+r)/2+1, r, s);
    pair<int, pll> ans = min(x, y);

    if(x.st == y.st) ans.nd = x.nd + y.nd;
    // db(p _ s _ ans.st _ ans.nd);
    return ans;
}

void update(int i, int j, int x, int p, int l, int r, int s) {
    push(p, l, r, s);
    if (i > j) return;
    if (l > j or r < i) return;
    if (l >= i and j >= r) { lz[s][p] += x; push(p, l, r, s); return; }

    update(i, j, x, 2*p, l, (l+r)/2, s);
    update(i, j, x, 2*p+1, (l+r)/2+1, r, s);

    st[s][p] = min(st[s][2*p], st[s][2*p+1]);
    if(st[s][2*p].st == st[s][2*p+1].st) st[s][p].nd = st[s][2*p].nd + st[s][2*p+1].nd;
}

//manipulating tree [l, r]
//odd: [l/2 + 1, (r + 1) / 2]
//even: [(l + 1)/2, r/2]

int n, m, l[N], r[N];
vector<pii> events[N];

void update_odd(int i, int j, int x) { update(i/2 + 1, (j + 1) / 2, x, 1, 1,  (m + 1) / 2, 1); }
void update_even(int i, int j, int x) { update((i + 1)/2, j/2, x, 1, 1,  (m + 1) / 2, 0); }

void update_seg(int i, int j, int x){
    update_odd(i, j, x);
    update_even(i, j, x);
}

pair<int, pll>  query_odd(int i, int j) { return query(i/2 + 1, (j + 1) / 2, 1, 1, (m + 1) / 2, 1);}
pair<int, pll>  query_even(int i, int j) { return query((i + 1)/2, j/2, 1, 1, (m + 1) / 2, 0); }

pair<int, pll>  query_seg(int i, int j){
    pair<int, pll> x = query_odd(i, j);
    pair<int, pll> y = query_even(i, j);

    pair<int, pll> ans = min(x, y);
    if(x.st == y.st) ans.nd = x.nd + y.nd;
    return ans;
}

void update_garden(int i, int x){
    //remove positions l[i] + 2k + 1
    if(l[i] % 2) update_even(l[i], r[i], x);
    else update_odd(l[i], r[i], x);

    //if r[i] - l[i] + 1 is even, remove positions [r[i] + 1, m]
    int parity = (r[i] - l[i] + 1) % 2;
    if(!parity){
        update_seg(r[i], m, x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(v, 63, sizeof(v));
    vector<int> painted(m + 5);
    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= (m + 1) / 2; j++){
            v[i][j] = {0, {2 * j - i, 1}};
        }
        build(1, 1, (m + 1) / 2, i);
    }
    
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
        events[l[i]].push_back({0, i});
        events[r[i]].push_back({1, i});

        update_garden(i, 1);

        painted[l[i]]++, painted[r[i] + 1]--;
    }
    int painted_pos = 0;
    for(int i = 1; i <= m; i++){
        painted[i] += painted[i - 1];
    }
    set<pii> current[2];
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        painted_pos = max(painted_pos, i);
        while(!painted[painted_pos] and painted_pos <= m) painted_pos++;

        if(current[0].size() or current[1].size()){
            int r_max = 0;
            if(current[0].size()) r_max = max(r_max, (current[0].rbegin())->st);
            if(current[1].size()) r_max = max(r_max, (current[1].rbegin())->st);
            pair<int, pll> qry_inside = {INF, {INF, INF}}, qry_outside = {INF, {INF, INF}};
            if(i % 2){
                if(current[(i % 2) ^ 1].empty()){
                    qry_inside = query_odd(i, r_max);
                    if(r_max <= m) qry_outside = query_seg(r_max + 1, m);
                }
                else{
                    int even_r_min = (current[(i % 2) ^ 1].begin())->st;
                    qry_inside = query_odd(i, even_r_min);
                }
            }
            else{
                if(current[(i % 2) ^ 1].empty()){
                    qry_inside = query_even(i, r_max);
                    if(r_max <= m) qry_outside = query_seg(r_max + 1, m);
                }
                else{
                    int even_r_min = (current[(i % 2) ^ 1].begin())->st;
                    qry_inside = query_even(i, even_r_min);
                }
            }
            if(qry_inside.st == 0) ans += (qry_inside.nd.st - qry_inside.nd.nd * (i - 1));
            if(qry_outside.st == 0) ans += (qry_outside.nd.st - qry_outside.nd.nd * (i - 1));
        }
        else{
            pair <int, pll> qry = query_seg(i, m);
            if(qry.st == 0){
                if(painted_pos > i){  
                    pair <int, pll> not_painted_qry = query_seg(i, painted_pos - 1);
                    if(not_painted_qry.st == 0){
                        qry.nd.st -= not_painted_qry.nd.st;
                        qry.nd.nd -= not_painted_qry.nd.nd;
                    }
                }
                ans += (qry.nd.st - qry.nd.nd * (i - 1));
            }
        }
        for(auto e : events[i]){  
            int parity = (r[e.nd] - l[e.nd] + 1) % 2;
            if(e.st == 0){
                if((l[e.nd] % 2))
                    current[parity].insert({r[e.nd], e.nd});
                else
                    current[parity ^ 1].insert({r[e.nd], e.nd});
                update_garden(e.nd, -1);
            }
            if(e.st == 1){
                if((l[e.nd] % 2))
                    current[parity].erase({r[e.nd], e.nd});
                else
                    current[parity ^ 1].erase({r[e.nd], e.nd});
            }
        }
        // db(ans _ i);
    }
    cout << ans << "\n";
    return 0;
}