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
const int N = 2e6+5;
const int M = 1e6;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("intel.in", "r", stdin);
    freopen("intel.out", "w", stdout);
    int n;
    cin >> n;
    vector <ll> psx(N), psy(N);
    pll old, ini;
    for(int i=0;i<=n;i++){
        pll cur;
        if(i < n){
            cin >> cur.st >> cur.nd;
        }
        else cur = ini;
        if(i){
            if(old.st == cur.st){
                ll up = max(old.nd,cur.nd);
                ll down = min(old.nd,cur.nd);
                psy[down + M + 1]++, psy[up + M + 1]--;
            }
            else{
                ll up = max(old.st,cur.st);
                ll down = min(old.st,cur.st);
                psx[down + M + 1]++, psx[up + M + 1]--;
            }
        }
        else ini = cur;
        old = cur;
    }
    ll ans = 0;
    for(int i=0;i<N;i++){
        if(i){
            psx[i] += psx[i-1];
            psy[i] += psy[i-1];
            if(psx[i] > 2) ans += psx[i] - 2;
            if(psy[i] > 2) ans += psy[i] - 2;
        }
    }
    cout << ans << "\n";
    return 0;
}