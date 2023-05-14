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
        vi a,trade;
        int n,m,p[105] = {0};
        cin >> n >> m;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            a.pb(x);
        }
        for(int i=0;i<m;i++){
            int x;
            cin >> x;
            p[x] = 1;
        }
        bool ok = true;
        while(ok){
            ok = false;
            for(int i=0;i<n-1;i++){
                if(a[i] > a[i+1]){
                    ok = true;
                    trade.pb(i);
                    swap(a[i],a[i+1]);
                }
            }
        }
        bool print = true;
        for(int i=0;i<trade.size();i++){
            if(!p[trade[i]+1]){
                print = false;
            }
        }
        if(print) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}