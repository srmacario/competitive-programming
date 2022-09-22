#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e6 + 5;

ll N, X, R, P, K, poison[M];
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> X >> R >> P >> K >> s;
    int last = K - 1;
    for(int i = 0; i < K; i++) poison[i] = true;
    for(int i = K; i < N; i++){
        if(s[i] == '0') continue;
        while(last >= 0 and s[last] == '1') last--;
        if(last < 0) break;
        // db((P * (N - last) - R * (N - i)) _ (P * (N - i)));
        if(P * (N - last) - R * (N - i) < P * (N - i)){
            poison[last] = false;
            poison[i] = true;
            // db(i);
            last--;
        }
    }
    ll ans = 0;
    ll p = 0, r = 0;
    for(int i = 0; i < N; i++){
        p += poison[i];
        r += s[i] - '0';
        r = max(0ll, r - poison[i]);
        ans += (X + P * p - R * r);
    }
    cout << ans << "\n";
    return 0;
}