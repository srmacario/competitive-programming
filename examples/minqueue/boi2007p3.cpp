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
const int N = 1e6+5;

int n,m,c,a[N];

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
    cin >> n >> m >> c;
    for(int i=1;i<=n;i++) cin >> a[i];
    minQueue mnq;
    maxQueue mxq;
    for(int i=1;i<=m;i++) mxq.push(a[i]), mnq.push(a[i]);
    bool ok = true;
    for(int l=1;l<=n-m+1;l++){
        int r = l+m-1;
        if(mxq.query() - mnq.query() <= c){
            cout << l << "\n";
            ok = false;
        }
        if(r!=n) mxq.pop(), mnq.pop(), mxq.push(a[r+1]), mnq.push(a[r+1]); 
    }
    if(ok) cout << "NONE\n";
    return 0;
}