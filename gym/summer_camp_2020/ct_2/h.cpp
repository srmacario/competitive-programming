#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

ll n, bit[N];
map <ll,ll> id,idr;
vector <pair<pll,pll>> sides;
vector <ll> yax;

void add( ll p, ll v){
    for(p+=2; p<N; p+= p&-p) bit[p] += v;
}

ll query(int p){
    ll r=0;
    for(p+=2;p;p -= p&-p) r += bit[p];
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int k=0;
    for(int i=0;i<n;i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        yax.pb(b);
        yax.pb(d);
        sides.pb({{a,0},{b,d}});
        sides.pb({{c,1},{b,d}});
    }
    sort(sides.begin(),sides.end());
    sort(yax.begin(),yax.end());
    ll cnt=1;
    id[yax[0]] = cnt;
    idr[cnt] = yax[0];
    for(int i=1;i<yax.size();i++){
        if(yax[i]!=yax[i-1]){
            cnt++;
        }
        id[yax[i]] = cnt;
        idr[cnt] = yax[i];
    }
    for(int i=0;i<sides.size();i++){
        sides[i].nd.st = id[sides[i].nd.st];
        sides[i].nd.nd = id[sides[i].nd.nd];
    }
    ll op = 0;
    for(int i=0;i<sides.size();i++){
        ll ya = sides[i].nd.st;
        ll yb = sides[i].nd.nd;
        ll x = sides[i].st.st;
        if(!sides[i].st.nd){
            add(ya,1);
            add(yb+1,-1);
            op++;
            if(op>=n-1){
                for(int j=1;j<=cnt;j++){
                    if(query(j)>=n-1){
                        cout << x << " " << idr[j] << "\n";
                        return 0;
                    }
                }
            }
        }
        else{
            add(ya,-1);
            add(yb+1,1);
        }
    }
    return 0;
}