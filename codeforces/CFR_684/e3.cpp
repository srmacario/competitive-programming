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

int stm[4*N], lazym[4*N], v[4*N];

void buildm (int p, int l, int r) {
    if (l == r) {stm[p] = v[l]; return;}
    buildm (2*p, l, (l+r)/2);
    buildm (2*p+1, (l+r)/2+1, r);
    stm[p] = max(stm[2*p], stm[2*p+1]);
}

void pushm (int p, int l, int r) {
    if (lazym[p]) {
        stm[p] = lazym[p];
        if (l != r) {
            lazym[2*p] = lazym[p];
            lazym[2*p+1] = lazym[p];
        }
        lazym[p] = 0;
    }
}

int querym (int p, int l, int r, int i, int j) {
    pushm(p, l, r);
    if (r < i or j < l) return -INF;
    if (i <= l and r <= j) return stm[p];
    int x = querym(2*p, l, (l+r)/2, i, j);
    int y = querym(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void updatem (int p, int l, int r, int i, int j, int k) {
    pushm(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazym[p] = k;
        pushm(p, l, r);
        return;
    }
    updatem(2*p, l, (l+r)/2, i, j, k);
    updatem(2*p+1, (l+r)/2+1, r, i, j, k);
    if (l != r) stm[p] = max(stm[2*p], stm[2*p+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}