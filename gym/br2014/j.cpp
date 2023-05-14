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
const int N = 505;

int bit[N][N], dist[N][N], r, c, n, val[N][N][3];
priority_queue <piii> pq;
// 0 = v, 1 = r, 2 = c

void add(int i, int j, int v) {
  for (; i < N; i+=i&-i)
    for (int jj = j; jj < N; jj+=jj&-jj)
      bit[i][jj] += v;
}

int query(int i, int j) {
  int res = 0;
  for (; i; i-=i&-i)
    for (int jj = j; jj; jj-=jj&-jj)
      res += bit[i][jj];
  return res;
}

// Whole BIT 2D set to 1
void init() {
  cl(bit,0);
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j)
      add(i, j, 1);
}

// Return number of positions set
int query(int imin, int jmin, int imax, int jmax) {
  return query(imax, jmax) - query(imax, jmin-1) - query(imin-1, jmax) + query(imin-1, jmin-1);
}

// Find all positions inside rect (imin, jmin), (imax, jmax) where position is set
void proc(int imin, int jmin, int imax, int jmax, int v, int tot) {
  if (tot < 0) tot = query(imin, jmin, imax, jmax);
  if (!tot) return;

  int imid = (imin+imax)/2, jmid = (jmin+jmax)/2;
  if (imin != imax) {
    int qnt = query(imin, jmin, imid, jmax);
    if (qnt) proc(imin, jmin, imid, jmax, v, qnt);
    if (tot-qnt) proc(imid+1, jmin, imax, jmax, v, tot-qnt);
  } else if (jmin != jmax) {
    int qnt = query(imin, jmin, imax, jmid);
    if (qnt) proc(imin, jmin, imax, jmid, v, qnt);
    if (tot-qnt) proc(imin, jmid+1, imax, jmax, v, tot-qnt);
  } else {
    // single position set!
    // now process position!!!
    dist[imin][jmin] = v + val[imin][jmin][0];
    pq.push({-dist[imin][jmin], {imin, jmin}});
    add(imin, jmin, -1);
  }
}

int dijkstra (int i, int j, int di, int dj) {
    init();
    while(!pq.empty()) pq.pop();
    memset(dist, 63, sizeof(dist));
    proc(i, j, i, j, 0, 1);

    while (!pq.empty()) {
        int ud = -pq.top().st;
        int ui = pq.top().nd.st, uj = pq.top().nd.nd; pq.pop();
        // db(ui _ uj);
        int imin, imax, jmin, jmax;
        imin = max(1, ui - val[ui][uj][1]), imax = min(r, ui + val[ui][uj][1]);
        jmin = max(1, uj - val[ui][uj][2]), jmax = min(c, uj + val[ui][uj][2]);
        // db(imin _ imax _ jmin _ jmax);
        // db(query(imin, jmin, imax, jmax));
        proc(imin, jmin, imax, jmax, ud, query(imin, jmin, imax, jmax));
    }
    if(dist[di][dj] == INF) return -1;
    return dist[di][dj] - val[di][dj][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c >> n;
    for(int k = 0; k < 3; k++){
        // 0 = v, 1 = r, 2 = c
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                cin >> val[i][j][k];
            }
        }
    }
    vector<pii> pos;
    for(int i = 0; i < n; i++){
        int pi, pj;
        cin >> pi >> pj;
        pos.pb({pi, pj});
    }
    for(int i = 0; i < n - 1; i++){
        cout << dijkstra(pos[i].st, pos[i].nd, pos[i + 1].st, pos[i + 1].nd);
        if(i < n - 2) cout << " ";
    }
    // cout << dijkstra(1, 1, 3, 4);
    cout << "\n";
    return 0;
}