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
const int N = 2e5+5;

int n, p[2*N], pos[2*N], d[N], s[2 * N], cur_s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        pos[p[i]] = i;
        p[i + n] = p[i];
    }
    for(int i = 0; i <= n / 2; i++) d[i] = i;
    for(int i = n; i >= (n + 1) / 2; i--) d[i] = n - i;
    ll tot = LINF, ans = 0;
    for(int i = 0; i < n; i++){
        int ini = 0;
        if(pos[i] <= i) ini = n - (i - pos[i]);
        else ini = (pos[i] - i);
        //calc s
        if(ini <= n/2){
            cur_s += 1;
            s[n/2 - ini] -= 1;
            s[(n+1)/2 - ini] -= 1;
            s[n - ini] += 2;
        }
        else{
            cur_s -= 1;
            s[n - ini] += 2;
            s[n + n/2 - ini] -= 1;
            s[n + (n + 1)/2 - ini] -= 1;
        }
        ans += d[ini];
    }
    for(int i = 0; i <= n; i++){
        tot = min(tot, ans);
        cur_s += s[i];
        ans += cur_s;
    }
    cout << tot << "\n";
    return 0;
}

/*
    0 1 2 3 4 4 3 2 1 0 1 2 3 4 4 3 2 1 0
    |       | |      | |       | |       |
    [0, n/2][n+1/2, n][n, n + n/2][n + n+1/2, 2n]
*/