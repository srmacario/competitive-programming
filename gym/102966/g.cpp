#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

pll p[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l, n;
    cin >> l >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].st >> p[i].nd;
    }
    sort(p, p + n);
    ll mn = l, mx = 0;
    for(int i = 0; i < n; i++){
        if(p[i].nd) mn = min(mn, p[i].st);
        else mx = max(mx, p[i].st);
    }
    ll ans;
    if(mn < mx){
        ans = (mx - mn) + max(l - mx, mn);
    }
    else{
        ans = max(l - mn, mx);
    }
    cout << ans << "\n";
    return 0;
}