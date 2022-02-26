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

ll cnt;

vi merge(vi v){
    int sz = (int)v.size();
    if(sz == 1) return v;
    vi l, r;
    for(int i = 0; i < (sz)/2; i++) l.pb(v[i]);
    for(int i = (sz)/2; i < sz; i++) r.pb(v[i]);
    l = merge(l), r = merge(r);
    int pl = 0, pr = 0;
    vi ans;
    while(pl < l.size() or pr < r.size()){
        if(pl >= l.size()) ans.pb(r[pr++]);
        else if(pr >= r.size()) ans.pb(l[pl++]);
        else if(r[pr] >= l[pl]) ans.pb(l[pl++]);
        else ans.pb(r[pr++]), cnt += l.size() - pl; //inversion
    }
    return ans;
}
