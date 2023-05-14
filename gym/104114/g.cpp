#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 5e5 + 5;

int n;
ll x[N], r[N], d[N], ans[N], unans[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    pll mn[3] = {{LINF, LINF}, {LINF, LINF}, {0, 0}};
    for(ll i = 0; i < n; i++){
        cin >> x[i];
        if(i){
            d[i] = x[i] - x[i - 1] - d[i - 1];
            mn[i % 2] = min(mn[i % 2], make_pair(d[i], i));
        }
    }
    for(int i = 0; i < n; i++) cin >> r[i];
    sort(r, r + n);
    for(int k = 0; k < 3; k++){
        if(mn[k].st == LINF) continue;
        unans[mn[k].nd] = ans[mn[k].nd] = r[0];
        for(int i = mn[k].nd - 1; i >= 0; i--){
            ll dif = x[i + 1] - x[i];
            ll need = dif - ans[i + 1];
            unans[i] = ans[i] = need;
        }
        for(int i = mn[k].nd + 1; i < n; i++){
            ll dif = x[i] - x[i - 1];
            ll need = dif - ans[i - 1];
            unans[i] = ans[i] = need;
        }
        sort(ans, ans + n);
        bool ok = true;
        for (int i = 0; i < n; i++){
            if (ans[i] != r[i]){
                ok = false;
                break;
            }
        }
        if(ok){
            for(int i = 0; i < n; i++) cout << unans[i] << " ";
            cout << "\n";
            break;
        }
    }
    return 0;
}