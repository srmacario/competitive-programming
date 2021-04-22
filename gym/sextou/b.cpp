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
const int N = 1e3+5, M = 1e6+5;

int n;
pll p[N];
map <pair<pll,pll>, set<int>> coef;
pair<ll, pair<pll, pll>> ans;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

void calc(){
    coef.clear();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            //calcula numerador denominador e constante
            ll num = p[i].nd - p[j].nd;
            ll den = p[i].st - p[j].st;
            ll cte = 0;
            //caso seja vertical
            if(den == 0){
                cte = p[i].st;
                num = 1;
                pair<pll,pll> line = {{cte,1}, {num, den}};
                coef[line].insert(i), coef[line].insert(j);
                ans = max({{coef[line].size(),line},ans});
                continue;
            }
            //caso seja horizontal
            if(num == 0){
                cte = p[i].nd;
                den = 1;
                pair<pll,pll> line = {{cte,1}, {num, den}};
                coef[line].insert(i), coef[line].insert(j);
                ans = max({coef[line].size(),line},ans);
                continue;  
            }  
            ll numcte = den*p[i].nd - num*p[i].st;
            ll dencte = den;
            if(!numcte) dencte = 0;
            else{
                ll mdcte = gcd(abs(numcte), abs(dencte));
                if(numcte*dencte < 0) numcte = -abs(numcte)/mdcte;
                else numcte = abs(numcte)/mdcte;
                dencte = abs(dencte)/mdcte;
            }
            ll mdc = gcd(abs(num), abs(den));
            if(num*den < 0) num = -abs(num)/mdc;
            else num = abs(num)/mdc;
            den = abs(den)/mdc;
            pair<pll, pll> line = {{numcte, dencte}, {num, den}};
            coef[line].insert(i), coef[line].insert(j);
            ans = max({coef[line].size(),line},ans);
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        ll x, y;
        scanf("%lld%lld", &p[i].st, &p[i].nd);
    }
    calc();
    int ok = ans.st;
    if(ok < 2*(n-ok)) printf("%d\n", n/3);
    else printf("%d\n", (n-ok));
    return 0;
}