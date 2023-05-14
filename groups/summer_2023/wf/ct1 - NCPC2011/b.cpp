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
const int N = 1e5+5;

int n, a[N];
ll bit[N], ans[N];

void add(int p, int v) {
  for (p += 2; p < N; p += p & -p) bit[p] += v;
}

ll query(int p) {
  ll r = 0;
  for (p += 2; p; p -= p & -p) r += bit[p];
  return r;
}

void add_ans(int p, ll v) {
  for (p += 2; p < N; p += p & -p) ans[p] += v;
}

ll query_ans(int p) {
  ll r = 0;
  for (p += 2; p; p -= p & -p) r += ans[p];
  return r;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll resp = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        add(x, 1);
        add_ans(x, (query(n) - query(x)));
        resp += (query_ans(n) - query_ans(x));
    }
    cout << resp << "\n";
    return 0;
}