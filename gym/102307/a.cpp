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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int n,t;

map <plll,set<plll>> coef;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        ll ans = 0;
        set <ll> hoz, ver;
        cin >> n;
        for(int i=0;i<n;i++){
            ll xa,ya,xb,yb;
            cin >> xa >> ya >> xb >> yb;
            ll num = (ya - yb), den = (xa - xb);
            //cout << num << " " << den << "\n";
            if(!num){
                if(!hoz.count(ya)) ans += ver.size();
                hoz.insert(ya);
            }
            if(!den){
                if(!ver.count(xa)) ans += hoz.size();
                ver.insert(xa);
            }
            if(num and den){
                ll sign = 1;
                if(num*den < 0) sign = -1;
                num = abs(num), den = abs(den);
                ll div = gcd(num,den);
                num /= div, den /= div;
                //cout << sign << " " << num << " " << den << "\n";
                ll num_l, den_l, sign_l = 1, div_l;
                num_l = ya*den - xa*num*sign, den_l = den;
                if(num_l*den_l < 0) sign_l = -1;
                num_l = abs(num_l), den_l = abs(den_l);
                //cout << sign_l << " " << num_l << " " << den_l << "\n";
                if(num_l){
                    div_l = gcd(num_l,den_l);
                    num_l /= div_l, den_l /= div_l;
                }
                else den_l = 0;
                //cout << sign_l << " " << num_l << " " << den_l << "\n";
                if(!coef[{sign,{num,den}}].count({sign_l,{num_l,den_l}})) ans += coef[{-sign,{den,num}}].size();
                coef[{sign,{num,den}}].insert({sign_l,{num_l,den_l}});
            }
        }
        cout << ans << "\n";
        coef.clear();
    }
    return 0;
}