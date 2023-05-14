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
        int n, c, q;
        string s;
        cin >> n >> c >> q;
        cin >> s;
        vector<plll> op;
        op.push_back({0ll, {1, n}});
        for(int i = 1; i <= c; i++){
            ll l, r;
            cin >> l >> r;
            op.push_back({op[i - 1].st + op[i - 1].nd.nd - op[i - 1].nd.st  + 1, {l, r}});
        }
        for(int i = 0; i < q; i++){
            ll pos;
            cin >> pos;
            while(pos > n){
                for(int j = 0; j < op.size(); j++){
                    if(op[j].st < pos and op[j].st + op[j].nd.nd - op[j].nd.st + 1 >= pos){
                        pos = (pos - op[j].st) + op[j].nd.st - 1;
                        break;
                    }
                }
            }
            cout << s[pos - 1] << "\n";
        }
    }
    return 0;
}