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
const int N = 3e6+5;

int t, n, a[N];

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll cntmax = 1;
    minQueue mnq;
    maxQueue mxq;
    mnq.push(a[1]), mxq.push(a[1]);
    ll mx = -LINF, mn = LINF, l = 1, r = 1;
    while(r<=n){
        mx = mxq.query(), mn = mnq.query();
        if(mx - mn <= t){
            r++;
            mnq.push(a[r]), mxq.push(a[r]);
        }
        else{
            l++;
            cntmax = max(cntmax, (r-l+1));
            mnq.pop(), mxq.pop();
        }
    }
    cntmax = max(cntmax, (r-l));
    cout << cntmax << "\n";
    return 0;
}