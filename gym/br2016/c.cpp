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
typedef pair<ll,pii> plii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

pii pts[N];
ll esc[N][N], inv[N], ans[N];
map<pii,int> med;

ll fexp (ll b, ll e, ll m = MOD) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

void pre(){
    for(int i=1;i<N;i++) inv[i] = fexp(i,MOD-2);
    for(int i=0;i<N;i++) esc[i][0]=1;
    for(long long i=1;i<N;i++) for(long long j=1;j<=i;j++) esc[i][j] = (((esc[i][j-1]*(i-j+1))%MOD)*inv[j])%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> pts[i].st >> pts[i].nd;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pii m = {pts[i].st + pts[j].st, pts[i].nd + pts[j].nd};
            med[m]++;
        }
    }
    for(auto m : med){
        for(int i=1;i<=m.nd;i++){
            ans[2*i] = (ans[2*i] + esc[m.nd][i])%MOD;
        }
    }
    for(int i=0;i<n;i++){
        pii pt = {2*pts[i].st,2*pts[i].nd};
        for(int j=1;j<=med[pt];j++){
            ans[2*j+1] = (ans[2*j+1] + esc[med[pt]][j])%MOD;
        }
    }
    ans[1] = n;
    for(int i=1;i<=n;i++) cout << ans[i] << (i == n ? "\n" : " ");
    return 0;
}