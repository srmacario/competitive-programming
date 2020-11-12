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

int n;
ll xh,yh,xw,yw;
pll h, w;
vector <pll> pts;

ll lis () {
    vector<ll> v;
    for (int i = 0; i < pts.size(); i++) {
        ll x = pts[i].nd;
        if (v.empty() or x >= v.back()) v.pb(x);
        else {
            ll pos = upper_bound(v.begin(), v.end(), x) - v.begin();
            v[pos] = x;
        }
    }
    return v.size();
}

bool cmp(pll a, pll b){
    if(h.st < w.st){
        if(a.st == b.st) return a.nd < b.nd;
        else return a.st < b.st;
    }
    else{
        if(a.st == b.st) return a.nd < b.nd;
        else return a.st > b.st;
    }
}

int main(){
    scanf("%d",&n);
    scanf("%lld%lld%lld%lld",&xh,&yh,&xw,&yw);
    h = {xh,yh}, w = {xw,yw};
    if(h.nd >= w.nd) swap(h,w);
    for(int i=0;i<n;i++){
        ll xi,yi;
        scanf("%lld%lld",&xi,&yi);
        if(xi >= min(h.st,w.st) and xi <= max(h.st,w.st) and yi >= min(h.nd,w.nd) and yi <= max(h.nd,w.nd)){
            pts.pb({xi,yi});
        }
    }
    sort(pts.begin(), pts.end(),cmp);
    ll ans = lis();
    printf("%lld\n",ans);
    return 0;
}