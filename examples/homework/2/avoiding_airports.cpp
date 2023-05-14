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

ll dp[N];

typedef long long type;
struct line { type b, m; };

struct cht{
    int nh = 0, pos = 0;
    vector<line> hull;

    bool check(line s, line t, line u) {
        return (t.b - s.b) / ld(s.m - t.m) < (u.b - s.b) / ld(s.m - u.m);
    }

    void update(line s) {
        while (nh >= 2 and !check(hull[nh-2], hull[nh-1], s)) hull.pop_back(), nh--;
        hull.pb(s);
        nh++;
    }
    type eval(line t, line s) { return (t.b - s.b) / ld(s.m - t.m);}

    type query(type x) {
        int lo = 0, hi = nh-1;
        while (lo < hi) {
            int mid = (lo+hi)/2+1;
            if (eval(hull[mid-1], hull[mid]) >= ld (x)) hi = mid-1;
            else lo = mid;
        }
        return hull[lo].b + hull[lo].m * x;
    }
};

cht h[N];

struct events{
    int id = 0, c = 0, op = 0;
    ll t = 0;
    events(int id, int c, int op, ll t) : id(id), c(c), op(op), t(t){}
    //bool operator <(const events e) const{return (t < e.t);}
};

bool cmp(events a, events b){
    return a.t < b.t;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<events> eve;
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b,s,e;
        cin >> a >> b >> s >> e;
        eve.pb(events(i,a,0,s));
        eve.pb(events(i,b,1,e));
    }
    sort(eve.begin(), eve.end(), cmp);
    for(int i = eve.size()-1;i >= 0; i--){
        if(eve[i].op){
            if(eve[i].c == n){
                dp[eve[i].id] = 0;
                continue;
            }
            if(h[eve[i].c].hull.size()) dp[eve[i].id] = (eve[i].t*eve[i].t) + h[eve[i].c].query(-eve[i].t);
            else dp[eve[i].id] = LINF;
        }       
        else{
            h[eve[i].c].update({dp[eve[i].id] + eve[i].t*eve[i].t,2*eve[i].t});
        }
    }
    cout << h[1].query(0) << "\n";
    return 0;
}