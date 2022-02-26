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

int n, m;
vector<int> adj[N];
vector <pii> adjw[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      adj[a].push_back(b);
      adj[b].push_back(a);
      adjw[a].push_back({c, b});
      adjw[b].push_back({c, a});
  }
}




