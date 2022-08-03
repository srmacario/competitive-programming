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
        int n, k;
        cin >> n >> k;
        vector <int> a(n + 5), cur(n + 5);
        set<int> div;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int j = 1; j <= k; j++) div.insert(a[i]/j);
        } 
        int ans = INF;
        set<int> used;
        for(auto p : div){
            bool ok = true;
            int tmp = 0;
            for(int i = 0; i < n; i++) cur[i] = INF;
            for(auto q : div){
                if(q.st >= p.st) cur[q.nd] = min(cur[q.nd], q.st);
            }
            for(int i = 0; i < n; i++){
                if(i == p.nd) continue;
                if(cur[i] == INF) ok = false;
                else{
                    tmp = max(tmp, {cur[i] - p.st});
                }
            }
            if(ok) ans = min(tmp, ans);
        }
        cout << ans << "\n";
    }
    return 0;
}