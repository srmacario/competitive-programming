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
const int N = 5e3+5;

ll a[N], dp[N][N];
int n,k,x;

struct maxQueue {
    deque <ll> d;
    queue <ll> q;

    void init () {
        while (d.size()) d.pop_front();
        while (q.size()) q.pop();
    }

    void push (ll x) {
        q.push(x);
        while (d.size() and d.back() < x) d.pop_back();
        //                  d.back() > x   <---  if min queue
        d.push_back(x);
    }

    void pop () {
        if (q.size() and q.front() == d.front()) d.pop_front();
        q.pop();
    }

    ll maxi () {
        if (!d.size()) return LINF;
        return d.front();
    }
};


int main(){
    scanf("%d%d%d",&n,&k,&x);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    ll ans = 0;
    ll mx = 0;
    for(int i=0;i<k;i++){
        dp[1][i] = a[i];
    }
    for(int i=2;i<=x;i++){
        maxQueue mq;
        int ini = max(0,i-1-k);
        for(int j=ini;j<i-1;j++) mq.push(dp[i-1][j]);
        for(int j=i-1;j<n;j++){
            if(mq.maxi()) dp[i][j] += mq.maxi() + a[j];
            else dp[i][j] = 0;
            if(j >= k) mq.pop();
            mq.push(dp[i-1][j]);
        }
    }
    for(int i=n-k;i<n;i++) ans = max(ans,dp[x][i]);
    cout << (ans ? ans : -1) << "\n";
    return 0;
}