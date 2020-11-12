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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

struct PT { 
  ll x, y; 
  PT() {} 
  PT(ll x, ll y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

ll cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
ll area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

vector <PT> pts;

void ConvexHull(vector<PT> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<PT> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

ll ternary_search(ll l, ll r, ll lm, ll rm){
    while(r - l > 10) {
        ll m1 = (l+r)/2;
        ll m2 = (l+r)/2 + 1;
        ll f1 = area2(pts[lm],pts[m1],pts[rm]);     
        ll f2 = area2(pts[lm],pts[m2],pts[rm]);      
        if (f1 < f2)
            l = m1;
        else if(f1 > f2)
            r = m2;
        else
            l = m1, r = m2;
    }
    ll ans = 0;
    for(int i=l;i<=r;i++){
        ll aux = area2(pts[lm], pts[i], pts[rm]);
        ans = max(ans,aux);
    }
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ll x,y;
        scanf("%lld %lld",&x, &y);
        PT p = PT(x,y);
        pts.pb(p);
    }
    ll ans = 0;
    ConvexHull(pts);
    for(int l=0;l<pts.size();l++){
        int lim = pts.size();
        if(!l) lim--;
        for(int r = l+1; r < lim;r++){
            ll partans = 0;
            partans += ternary_search(l+1,r-1,l,r);
            partans += ternary_search(r+1,pts.size()-1,r,l); 
            ans = max(partans,ans);
        }
    }
    printf("%lld",ans/2);
    if(ans%2) printf(".5");
    else printf(".0");
    printf("\n");
    pts.clear();

    return 0;
}