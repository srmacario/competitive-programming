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

bool dfs(ll x, ll k){
    if(x == k) return true;
    ll cur = x;
    for(ll i = 32; i >= 0; i--){
        if((1ll<<i)&x){
            bool ok = dfs(cur + x, k);
            if(ok) return true;
            cur -= 1ll<<i;
        }
    }
    return false; 
}

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        ll u, v;
        scanf("%lld%lld", &u, &v);
        bool ok = false;
        if(u > v) ok = false;
        else ok = dfs(u, v);
        printf("%s", (ok ? "Yes\n" : "No\n"));
    }
    return 0;
}