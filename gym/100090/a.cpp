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
const int N = 3e3+5;

int n, m, q, vis[N*N], cnt;
vii row, col;
string grid[N];

inline bool is_bounded(pii point, pii lim_i, pii lim_j){
    return (point.st < lim_i.nd and point.st > lim_i.st and point.nd < lim_j.nd and point.nd > lim_j.st);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    row.resize(n);
    col.resize(m);
    for(int i = 0; i < n; i++) row[i].pb(-1);
    for(int i = 0; i < m; i++) col[i].pb(-1);
    for(int i = 0; i < n; i++){
        string s;
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#') row[i].pb(j), col[j].pb(i);
        }
    }
    for(int i = 0; i < n; i++) row[i].pb(INF);
    for(int i = 0; i < m; i++) col[i].pb(INF);
    cin >> q;
    for(int i = 0; i < q; i++){
        int x[2], y[2], lb_i, lb_j, ub_i, ub_j;

        cin >> x[0] >> y[0] >> x[1] >> y[1];

        --x[0], --y[0], --x[1], --y[1];

        //Intersections points
        pii pos[2] = {{x[0], y[1]}, {x[1], y[0]}};
        //Validating first intersection point
        bool ok = false;
        
        for(int j = 0; j < 2; j++){
            lb_j = *lower_bound(row[pos[j].st].begin(), row[pos[j].st].end(), pos[j].nd);
            if(lb_j != pos[j].nd) lb_j = *(lower_bound(row[pos[j].st].begin(), row[pos[j].st].end(), pos[j].nd) - 1);
            ub_j = *upper_bound(row[pos[j].st].begin(), row[pos[j].st].end(), pos[j].nd);

            lb_i = *lower_bound(col[pos[j].nd].begin(), col[pos[j].nd].end(), pos[j].st);
            if(lb_i != pos[j].st) lb_i = *(lower_bound(col[pos[j].nd].begin(), col[pos[j].nd].end(), pos[j].st) - 1);
            ub_i = *upper_bound(col[pos[j].nd].begin(), col[pos[j].nd].end(), pos[j].st);

            pii lim_i = {lb_i, ub_i}, lim_j = {lb_j, ub_j};
            if(is_bounded(pos[j^1], lim_i, lim_j) and grid[pos[j].st][pos[j].nd] != '#') ok = true;
        }
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}