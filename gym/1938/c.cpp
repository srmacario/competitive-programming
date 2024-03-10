#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define endl '\n'
#define int long long

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

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if(n == 1) {
            cout << (1ll << v[0]) - 1 << "\n";
            continue;
        }
        bool foi = true;
        vector<int> dif;
        for(int i = 1; i < n; i++) {
            dif.push_back(v[i] - v[i - 1]);
            if(dif[i - 1] > 1) 
                foi = false;
        }
        if(!foi) {
            cout << -1 << endl;
            continue;
        }
        vector<int> bits(65, 2);
        int sig = -dif.front() + 2;
        int start = 0;
        if(dif.front() == 1) {
            bits[0] = 0;
        } else {
            start = (1ll << (-dif.front() + 1)) - 1;
            for(int j = 0; j <= -dif.front(); j++)
                bits[j] = 1;
            bits[-dif.front() + 1] = 0;
        }
        int cur = start;
        bool ok = true;
        for(int i = 0; i < n - 1; i++) {
            if(cur == (1ll << sig) - 1) {
                if(-dif[i] < sig - 1) {
                    ok = false;
                    break;
                }
                for(int j = sig; j <= -dif[i]; j++) {
                    bits[j] = 1;
                    cur += (1ll << j);
                    start += (1ll << j);
                }
                cur++;
                bits[-dif[i] + 1] = 0;
                sig = -dif[i] + 2;
            } else {
                int prev = __builtin_popcountll(cur);
                cur++;
                int nxt = __builtin_popcountll(cur);
                if(nxt - prev != dif[i]) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            int curb = __builtin_popcountll(start);
            for(int j = sig; j < sig + v[0] - curb; j++) {
                start += (1ll << j);
            }
            bool f = true;
            for(int cop = start; cop < start + n; cop++) {
                if(__builtin_popcountll(cop) != v[cop - start]) {
                    f = false;
                    break;
                }
            }
            if(f)
                cout << start << endl;
            else
                cout << -1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}