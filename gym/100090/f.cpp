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
const int N = 2e5+5;

int n, bit[N];
ll ans;
set <pii> s;

void add (int p, ll v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

int query (int p) {
    ll r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

set<pii> ::iterator find_interval(int x){
    //get lb for interval
    auto it = s.lower_bound({x, 0});

    //if its not the first, decrease it  
    if(it != s.begin()) it--;

    //after decreasing, if the right bound is lesser, increase it
    if(it -> nd < x) it++;

    return it;
}

void update(int x){
    // get interval 
    auto it = find_interval(x);

    int l = it -> st, r = it -> nd;
    //update whole interval with one comparison more  
    add(l, 1), add(r + 1, -1);

    //erase interval and split it into two
    s.erase(it);
    
    if(l <= x - 1) s.insert({l, x - 1});
    if(r >= x + 1) s.insert({x + 1, r});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    s.insert({1, n});
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        //bit stores number of comparisons
        ans += query(x);
        //update interval
        update(x);
    }
    cout << ans << "\n";
    return 0;
}