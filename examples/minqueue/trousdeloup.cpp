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
const int N = 1e5+5;

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
    ll d,n,p;
    cin >> n >> p >> d;
    vector <ll> w(n+5);
    for(int i=1;i<=n;i++){
        cin >> w[i];
        w[i] += w[i-1];
    }
    maxQueue mxq;
    ll l = 1, r = d, ans = d, sum = w[d];
    mxq.push(w[d]);
    while(r <= n){
        while(r<=n and sum - mxq.query() <= p){
            ans = max(ans, (r-l+1));
            sum = w[++r] - w[l-1];
            mxq.push((w[r] - w[r-d]));
        }
        mxq.pop();
        sum = w[r] - w[++l - 1];
    }
    cout << ans << "\n";
    return 0;
}