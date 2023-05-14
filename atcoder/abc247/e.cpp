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

int v[N];
int n, x, y;

ll solve(int l, int r){
    ll ans = 0;
    int cnt_x = 0, cnt_y = 0;
    for(int i = l, j = l; i <= r; i++){
        while(!(cnt_x and cnt_y) and j <= r){
            if(v[j] == x) cnt_x++;
            if(v[j] == y) cnt_y++;
            j++;
        }
        // db(i _ j _ r);
        if(cnt_x and cnt_y){
            ans += (r - j + 2);
        }
        if(v[i] == x) cnt_x--;
        if(v[i] == y) cnt_y--;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    ll tot = 0;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int l = 1, r = 1; l <= n; l++){
        while(r <= n and v[r] >= y and v[r] <= x){
            r++;
        }
        if(r > l){
            ll cur = solve(l, r - 1);
            tot += cur;
        }
        l = r;
        r++;
    }
    cout << tot << "\n";
    return 0;
}