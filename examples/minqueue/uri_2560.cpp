#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 2e5+5;

ll n,b,a[N],ps[N];

struct minQueue{
    deque<pll> dq;
    ll ini, fim;
    minQueue(){
        ini = 1, fim = 0;
    }
    void push(ll x){
        while(!dq.empty() and dq.back().st >= x) dq.pop_back();
        dq.pb({x,++fim});
    }
    void pop(){
        if(!dq.empty() and (dq.front().nd == ini++)) dq.pop_front();
    }
    ll query(){
        return dq.front().st;
    }
};

struct maxQueue{
    deque<pll> dq;
    ll ini, fim;
    maxQueue(){
        ini = 1, fim = 0;
    }
    void push(ll x){
        while(!dq.empty() and dq.back().st <= x) dq.pop_back();
        dq.pb({x,++fim});
    }
    void pop(){
        if(!dq.empty() and (dq.front().nd == ini++)) dq.pop_front();
    }
    ll query(){
        return dq.front().st;
    }
};

int main(){
    while(scanf("%lld %lld", &n, &b) != EOF){
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            ps[i] = a[i] + ps[i-1];
        }
        minQueue mnq;
        maxQueue mxq;
        ll ans = 0;
        for(int i=1;i<=b;i++){
            mnq.push(a[i]), mxq.push(a[i]);
        }
        for(int l = 1;l<=(n-b+1);l++){
            ll r = l + b - 1;
            ans += ps[r] - ps[l-1] - mxq.query() - mnq.query();
            mxq.pop(), mnq.pop();
            if(r!=n) mxq.push(a[r+1]), mnq.push(a[r+1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}