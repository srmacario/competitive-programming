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

int n,p;
ld P[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    cin >> n >> p;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        P[i] = (r/p - (l-1)/p)/ld(r-l+1);
        db(P[i]);
    }
    ld ans = 0;
    for(int i=0;i<n;i++){
        ans += (P[i] + P[(i+1)%n] - P[i]*P[(i+1)%n]) * 2000;
    }
    cout << ans << "\n";
    return 0;
}