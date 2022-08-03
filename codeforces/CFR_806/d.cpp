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
        set<string> cmp;
        vector<string> s(n);
        for(int i = 0; i < n; i++){
            cin >> s[i];
            cmp.insert(s[i]);
        }
        string ans;
        for(int i = 0; i < n; i++){
            bool ok = false;
            for(int j = 1; j < s[i].size(); j++){
                string l = s[i].substr(0, j);
                string r = s[i].substr(j, s[i].size() - j);
                ok |= (cmp.count(l) and cmp.count(r));
            }
            ans += ('0' + ok);
        }
        cout << ans << "\n";
    }
    return 0;
}