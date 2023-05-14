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
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        s += s;
        vector<int> g;
        for(int i = 0; i < 2 * n; i++){
            if(s[i] == 'g') g.push_back(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == c){
                int dist = (*lower_bound(g.begin(), g.end(), i) - i);
                ans = max(ans, dist);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}