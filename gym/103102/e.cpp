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
const int N = 5e5+5;

ll ps[3][N], box[3][3], a[N], ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    box[0][0]++;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ps[0][i] = ps[0][i-1];
        ps[1][i] = ps[1][i-1];
        ps[2][i] = ps[2][i-1];
        ps[a[i]%3][i] = (ps[a[i]%3][i] + 1)%3;
        int x = ps[1][i], y = ps[2][i];
        ans += box[x][y];
        ans += box[(x+2)%3][y];
        ans += box[x][(y+2)%3];
        box[x][y]++;
    }
    cout << ans << "\n";
    return 0;
}