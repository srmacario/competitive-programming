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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x[2][2], y[2][2];
    int dist = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) cin >> x[i][j] >> y[i][j];
    }
    dist = max((max(x[0][1], x[1][1]) - min(x[0][0], x[1][0])), (max(y[0][1], y[1][1]) - min(y[0][0], y[1][0])));
    cout << dist * dist << "\n";
    return 0;
}