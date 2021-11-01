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

struct minmaxQueue {
    deque <ll> d;
    queue <ll> q;
    int t;

    void init (int min_max) {
        t = min_max;
        while (d.size()) d.pop_front();
        while (q.size()) q.pop();
    }

    void push (ll x) {
        q.push(x);
        if(t) while (d.size() and d.back() < x) d.pop_back();
        else  while (d.size() and d.back() > x) d.pop_back();
        d.push_back(x);
    }

    void pop () {
        if (q.size() and q.front() == d.front()) d.pop_front();
        q.pop();
    }

    ll query () {
        if (!d.size()) return LINF;
        return d.front();
    }
};

ll n, k;
ll ans;
minmaxQueue mq[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<ll> a(n);
    mq[0].init(0), mq[1].init(1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int r = 0, l = 0; r < n; r++){
        mq[0].push(a[r]), mq[1].push(a[r]);
        while(mq[1].query() - mq[0].query() > k){
            mq[0].pop();
            mq[1].pop();
            l++;
        }
        ans += r - l + 1ll;
    }
    cout << ans << "\n";
    return 0;
}