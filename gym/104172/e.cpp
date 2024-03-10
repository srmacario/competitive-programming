#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

typedef long long ll;

const int N = 1e6 + 5;

int n, k, lazy[4*N];
pair<int, int> st[4*N];
vector<int> pos[N];

void build(int p, int l, int r){
    st[p] = {0, r - l + 1};
    if(l == r) return;

    int m = (l + r) >> 1;
    build(2*p, l, m);
    build(2*p + 1, m + 1, r);
}

void push(int p, int l, int r){
    if(lazy[p]){
        st[p].st += lazy[p];
        if(l != r){
            lazy[2*p] += lazy[p];
            lazy[2*p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void update(int p, int l, int r, int i, int j, int v){
    push(p, l, r);
    if(r < i or l > j) return;
    if(i <= l and r <= j){
        lazy[p] += v;
        push(p, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(2*p, l, m, i, j, v);
    update(2*p + 1, m + 1, r, i, j, v);
    st[p] = min(st[2*p], st[2*p + 1]);
    if(st[2*p].st == st[2*p + 1].st) st[p].nd = st[2*p].nd + st[2*p + 1].nd;
}

pair<int, int> query(int p, int l, int r, int i, int j){
    push(p, l, r);
    if(r < i or l > j) return {INT_MAX, 0};
    if(i <= l and r <= j) return st[p];

    int m = (l + r) >> 1;
    pair<int, int> x = query(2*p, l, m, i, j);
    pair<int, int> y = query(2*p + 1, m + 1, r, i, j);
    if(x.st == y.st) return {x.st, x.nd + y.nd};
    return min(x, y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    build(1, 1, n);
    for(int i = 1; i < N; i++) pos[i].push_back(0);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if(pos[a].size() > k){
            update(1, 1, n, pos[a][(int)pos[a].size() - k - 1] + 1, pos[a][(int)pos[a].size() - k], -1);
        }
        pos[a].push_back(i);
        if(pos[a].size() > k){
            update(1, 1, n, pos[a][(int)pos[a].size() - k - 1] + 1, pos[a][(int)pos[a].size() - k], 1);
        }
        pair<int, int> q = query(1, 1, n, 1, i);
        if(q.st == 0){
            ans += q.nd;
        }
    }
    cout << ans << "\n";
    return 0;
}