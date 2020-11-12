#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a,b,pf,nf;
        a.pb(0),b.pb(0),pf.pb(0),nf.pb(0);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            a.pb(x);
            pf.pb(pf[i-1]), nf.pb(nf[i-1]);
            if(x == 1) pf[i]++;
            if(x == -1) nf[i]++;
        }
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            b.pb(x);
        }
        bool ok = true;
        for(int i=n;i>=1;i--){
            if(b[i] == a[i]) continue;
            else if(b[i] > a[i]){
                if(!pf[i-1]) ok = false; 
            }
            else{
                if(!nf[i-1]) ok = false; 
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}