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
const int N = 1e5+5, M = 205;

ll tst[M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            ll b;
            cin >> b;
            b--;
            tst[i] += 1ll<<b;
        }
    }
    pii ans = {INF, INF};
    for(int i = 1; i < (1<<n); i++){
        int cnt = 0;
        ll t = 0;
        for(ll j = 0; j < n; j++){
            if((1<<j)&i) t |= tst[j], cnt++;
        }
        pii partans = {cnt, i};
        if(t == (1ll<<m)-1) ans = min(ans, partans);
    }
    cout << ans.st << "\n";
    for(int j = 0; j < n; j++){
        if((1<<j)&ans.nd) cout << j+1 << " ";
    }
    cout << "\n";
    return 0;
}