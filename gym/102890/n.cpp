#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3ff3, MOD = 1e9+7;
const int N = 1e5+5, M = 105, D = 5005;

int d, b, m, p[M];
ll dp[M][D];

struct MinQueue{
    int sz = 0;
    deque<pll> dq;
    
    bool empty(){ return dq.empty(); }
    void clear(){ sz = 0; dq.clear(); }
    ll min(){ return dq.front().first; }
    int size(){ return sz; }

    void push(ll x){
        ll amt = 1;
        while(dq.size() and dq.back().first >= x)
            amt += dq.back().second, dq.pop_back();
        dq.push_back({x, amt});
        sz++;
    }

    void pop(){
        dq.front().second--, sz--;
        if(!dq.front().second) dq.pop_front();
    }
};

bool calc(int f){
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= d; j++)
            dp[i][j] = 0;
    
    for(int j = 1; j <= d; j++) dp[0][j] = b + 1;

    for(int i = 1; i <= m; i++){
        MinQueue minqueue;
        for(int j = 0; j < f; j++) minqueue.push(dp[i - 1][j]);
        for(int j = 0; j <= d; j++){
            if(j + f <= d) minqueue.push(dp[i - 1][j + f]);
            if(j - f > 0) minqueue.pop();
            dp[i][j] = 1ll * abs(j - p[i]) + minqueue.min();
        }
    }
    for(int j = d - f; j <= d; j++) if(dp[m][j] <= b) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> d >> b >> m;
    for(int i = 1; i <= m; i++) cin >> p[i];
    sort(p + 1, p + m + 1);
    int l = 0, r = d;
    while(l < r){
        int mid = (l + r)/2;
        if(calc(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return 0;
}