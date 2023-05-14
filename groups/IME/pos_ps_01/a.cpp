#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define dbs(x) cerr << x << endl;
#define _ << ", " <<

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5;

struct SegTreeNode{
    int idx = -1;
    ull hash = 0;
    ull inv_hash = 0;
};

int n, q, ini[N], fim[N];
ull pr = 1777771;
ull pot[N];
string v;

SegTreeNode st[4*N];

//l - mid , mid + 1 - r
// 3 2 1 0, 2 1 0

//l - mid , mid + 1 - r
// 0 1 2 3, 0 1 2
void merge(int p, int l, int r){
    int mid = (l + r) >> 1;
    st[p].hash = ((st[2 * p].hash * pot[r - mid]) % MOD + st[2 * p + 1].hash)%MOD;
    st[p].inv_hash = ((st[2 * p + 1].inv_hash * pot[mid - l + 1])%MOD + st[2 * p].inv_hash) % MOD;
    st[p].idx = (r - l);
}
// 0 - idx_lft 0 1 2 3
// 0 - idx_rgt 0 1 2 3 4
SegTreeNode query_merge(SegTreeNode left, SegTreeNode right){
    SegTreeNode ans;
    ans.hash = ((left.hash * pot[right.idx + 1]) % MOD + right.hash) % MOD;
    ans.inv_hash = ((right.inv_hash * pot[left.idx + 1]) % MOD + left.inv_hash) % MOD;
    ans.idx = (right.idx + left.idx + 1);
    // db(left.hash _ right.hash _ ans.hash _ ans.inv_hash);
    return ans;
}

void build(int p = 1, int l = 1, int r = static_cast<int>(v.size()) - 1){
    if(l == r){
        st[p].hash = (v[l] - 'a' + 1);
        st[p].inv_hash = (v[l] - 'a' + 1);
        st[p].idx = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);

    merge(p, l, r);
}

SegTreeNode query(int i, int j, int p = 1, int l = 1, int r = static_cast<int>(v.size()) - 1){
    SegTreeNode ans;
    if(r < i or l > j) return ans;
    if(i <= l and r <= j) return st[p];
    int mid = (l + r) >> 1;
    SegTreeNode left = query(i, j, 2 * p, l, mid);
    SegTreeNode right = query(i, j, 2 * p + 1, mid + 1, r);
    return query_merge(left, right);
}

void update(int x, char c, int p = 1, int l = 1, int r = static_cast<int>(v.size()) - 1){
    if(r < x or l > x) return;
    if(l == r and l == x){
        st[p].hash = (c - 'a' + 1);
        st[p].inv_hash = (c - 'a' + 1);
        st[p].idx = 0;
        return;
    }
    int mid = (l + r) >> 1;
    update(x, c, 2 * p, l, mid);
    update(x, c, 2 * p + 1, mid + 1, r);
    merge(p, l, r);
}

bool palindrome(int i, int j, int li, int ri, int lj, int rj){
    int sz = (ri - li + 1) + (rj - lj + 1);
    ull hash_l = 0;
    ull hash_r = 0;
    //case hash from left will be from left, right may split
    if(ri - li + 1 <= sz/2){
        //(li - 1, ri - 1) + (lj - 1, lj - 1 + (dif - 1)) == (rj - sz/2, rj - 1)
        //hash from left
        hash_l = query(ini[i] + li - 1, ini[i] + ri - 1).hash;
        int dif = sz/2 - (ri - li + 1);
        //case: hash left + hash right 1 == hash right 2
        if(dif) hash_l = ((hash_l * pot[dif]) % MOD + (query(ini[j] + lj - 1, ini[j] + lj + dif - 2).hash)%MOD)%MOD;
        hash_r = query(ini[j] + rj - sz/2, ini[j] + rj - 1).inv_hash;
    }
    //case hash from left will split
    else{
        //hash from left
        //case: hash left 1 == hashleft 2 + hash right
        //(li - 1, li - 1 + (sz/2 - 1)) == (lj - 1, rj - 1) + (rj - 1 - (sz/2 - 1), rj - 1)
        hash_l = query(ini[i] + li - 1, ini[i] + li + sz/2 - 2).hash;
        hash_r = query(ini[j] + lj - 1, ini[j] + rj - 1).inv_hash;
        int dif = sz/2 - (rj - lj + 1);
        if(dif) hash_r = ((pot[dif] * hash_r)%MOD + query(ini[i] + ri - dif, ini[i] + ri - 1).inv_hash) % MOD;
    }
    return (hash_l == hash_r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    v += '$';
    pot[0] = 1;
    for(int i = 1; i < N; i++) pot[i] = (pot[i - 1] * pr)%MOD;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        ini[i] = v.size();
        v += s;
        fim[i] = static_cast<int>(v.size()) - 1;
    }
    build();
    for(int k = 0; k < q; k++){
        int op, i, j;
        cin >> op >> i >> j;
        if(op == 1){
            char c;
            cin >> c;
            update(ini[i] + j - 1, c);
        }
        else{
            int l[2], r[2];
            cin >> l[0] >> r[0];
            cin >> l[1] >> r[1];
            SegTreeNode left = query(ini[i] + l[0] - 1, ini[i] + r[0] - 1);
            SegTreeNode right = query(ini[j] + l[1] - 1, ini[j] + r[1] - 1);
            if(op == 2){
                if(left.hash == right.hash) cout << "equal\n";
                else cout << "different\n";
            }
            if(op == 3){
                bool ok = palindrome(i, j, l[0], r[0], l[1], r[1]);
                if(ok) cout << "cool\n";
                else cout << "not so cool\n";
            }
        }
    }
    return 0;
}