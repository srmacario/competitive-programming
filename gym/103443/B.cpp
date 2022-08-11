#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int pre[N], suf[N]; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    string a, b;

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a >> b;

        if (a[0] == b[0]) pre[0] = 1;
        else pre[0] = 0;

        if (a[n-1] == b[n-1]) suf[n-1] = 1;
        else suf[n-1] = 0;

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + (a[i] == b[i] ? 1 : 0);
        }

        for (int i = n-2; i >= 0; i--) {
            suf[i] = suf[i+1] + (a[i] == b[i] ? 1 : 0);
        }

        int mx = 0;
        int lans = 0, rans = 0;

        for (int i = 0; i < n; i++) {
            int m = 0;
            int l = i, r = i;
            while (l >= 0 and r < n) {
                int val = 0;
                if (l >= 1) val += pre[l-1];
                if (r+1 < n) val += suf[r+1];
                if (b[l] == a[r]) m++;
                if (b[r] == a[l]) m++;
                if (l == r and a[l] == b[r]) m--;
                
                val += m;

                if (val > mx or (val == mx and (r-l) < (rans-lans)) or (val == mx and (r-l) == (rans-lans) and l < lans)) {
                    mx = val;
                    lans = l;
                    rans = r;
                }

                l--, r++;
            }
        }

          for (int i = 0; i+1 < n; i++) {
            int m = 0;
            int l = i, r = i+1;
            while (l >= 0 and r < n) {
                int val = 0;
                if (l >= 1) val += pre[l-1];
                if (r+1 < n) val += suf[r+1];
                if (b[l] == a[r]) m++;
                if (b[r] == a[l]) m++;

                val += m;

                if (val > mx or (val == mx and (r-l) < (rans-lans)) or (val == mx and (r-l) == (rans-lans) and l < lans)) {
                    mx = val;
                    lans = l;
                    rans = r;
                }

                l--, r++;
            }
        }

        cout << pre[n-1] << " " << mx << " " << lans+1 << " " << rans+1 << "\n";
    }

    return 0;
}