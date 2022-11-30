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
        int n, q;
        cin >> n >> q;
        vector<ll> h(n + 5);
        for(int i = 1; i <= n; i++) cin >> h[i];
        vector<ll> ans(q);
        vector<pii> queries(q);
        for(int i = 0; i < q; i++){
            cin >> queries[i].st;
            queries[i].nd = i;
        }
        sort(queries.begin(), queries.end());
        int cur_pos = 1;
        ll cur_height = 0;
        for(int l = 0; l < q; l++){
            while(cur_pos <= n and queries[l].st >= h[cur_pos]){
                cur_height += h[cur_pos];
                cur_pos++;
            }
            ans[queries[l].nd] = cur_height;
        }
        for(int i = 0; i < q; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}