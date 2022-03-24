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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vi a(n + 5), trade(n + 5);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            trade[x - 1] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - 1; j++){
                // db(a[j] _ a[j + 1] _ trade[j]);
                if(a[j] > a[j + 1] and trade[j]) swap(a[j], a[j + 1]);
            }
        }
        bool ok = true;
        for(int i = 0; i < n - 1; i++) if(a[i] > a[i + 1]) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}