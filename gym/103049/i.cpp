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
const int N = 405;

int n, d[N], t[3][N], ini[3][N][N], fim[3][N][N], vis[3][3][N][N];

bool check(int i, int j, int pi, int pj){
    if(~vis[i][j][pi][pj]) return vis[i][j][pi][pj];
    if(pi == pj) return vis[i][j][pi][pj] = 0;
    for(int t = 0; t < 2; t++){
        for(int k = pj; k != pi; k = (k+1)%n){
            if(ini[i][pi][k] < fim[j][pj][k])
                return vis[i][j][pi][pj] = vis[j][i][pj][pi] = 0;
        }
        swap(i, j);
        swap(pi, pj);
    }
    return vis[i][j][pi][pj] = vis[j][i][pj][pi] = 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(vis, -1, sizeof(vis));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin >> t[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            fim[i][j][j] = t[i][j];
            for(int k = (j+1)%n; k != j; k = (k+1)%n){
                ini[i][j][k] = fim[i][j][(k-1+n)%n] + d[(k-1+n)%n];
                fim[i][j][k] = ini[i][j][k] + t[i][k];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(check(0, 1, i, j) and check(1, 2, j, k) and check(0, 2, i, k)){
                    cout << i+1 << " " << j+1 << " " << k+1 << "\n";
                    return 0;
                }
                // db(i _ j _ k);
            }
        }
    }
    cout << "impossible\n";
    return 0;
}