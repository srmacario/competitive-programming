/*
Given an array of 2n numbers, each number from 1 to n in it occurs exactly twice.
We say that the segment y is nested inside the segment x if both occurrences of the number y are between the occurrences of the number x.
Find for each segment i how many segments that are nested inside it.
*/
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
const int N = 2e5+5;


int st[4*N], v[N], ans[N];

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x + y;
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {
        st[p] = v;
        return;
    }
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    st[p] = st[2*p] + st[2*p+1];
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 2*n; i++){
        int x;
        scanf("%d", &x);
        if(v[x]){
            ans[x] = query(1, 1, 2*n, v[x], i);
            // db(v[x] _ ans[x]);
            update(1, 1, 2*n, v[x], 1);
        }
        v[x] = i;
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}