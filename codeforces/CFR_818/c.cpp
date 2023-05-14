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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        pii mx = {0, -1};
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(mx, {a[i], i});
        }
        bool ok = true;
        for(int i = 0; i < n; i++){
            cin >> b[i];
            mx = max(mx, {b[i], i});
            if(b[i] < a[i]) ok = false;
        }
        if(!ok){
            cout << "No\n";
            continue;
        }
        for(int i = 0; i < n; i++){
            if(b[i] == a[i]) continue;
            if(b[i] - b[(i + 1) % n] > 1){
                ok = false;
                break;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}