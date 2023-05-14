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
const int N = 2e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k,m;
        cin >> n >> k >> m;
        vi b(m);
        for(int i=0;i<m;i++) cin >> b[i];
        int sz = n-m;
        if(sz%(k-1)){
            cout << "NO\n";
            continue;
        }
        bool ok = false;
        int l = 0, pos = 0;
        for(int i=1;i<=n;i++){
            if(b[pos] != i) l++;
            else{
                if(l>=(k-1)/2 and sz-l >= (k-1)/2){
                    ok = true;
                    break;
                }
                pos++;
                if(pos == m){
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}