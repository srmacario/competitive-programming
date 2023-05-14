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
const int N = 1e3+5;

int n, m;
int grid[N][N], dif[N][N];

void build () {
    for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++)
        dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
}

int query (int x, int y, int s) {
    return dif[x][y] - dif[x-s][y] - dif[x][y-s+1] + dif[x-s][y-s+1];
}

bool check(int mid){
    if(mid == 1) return true;
    for(int j = m - 1; j >= mid - 1; j--){
        for(int i = n; i >= mid; i--){
            if(!query(i,j,mid)) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string x;
        cin >> x;
        for(int j = 0; j < m; j++){
            grid[i][j+1] = (x[j] == 'G');
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++){
            dif[i][j] = grid[i][j + 1]^grid[i][j];
        }
    }
    build();
    int l = 1, r = min(n, m);
    while(l < r){
        int mid = (l + r + 1)/2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l*l << "\n";
    return 0;
}