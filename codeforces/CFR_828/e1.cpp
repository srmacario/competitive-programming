#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll a, b, c, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        ll old_a = a, old_b = b;
        ll ans = 0;
        pll par_ans;
        bool ok = false;
        vector<ll> primes;
        //get primes
        for(ll i = 2; i * i <= a; i++){
            ll cur = i;
            while(!(a % cur)){
                a /= cur;
                primes.push_back(cur);
            }
        }
        if(a != 1) primes.push_back(a);
        for(ll i = 2; i * i <= b; i++){
            ll cur = i;
            while(!(b % cur)){
                b /= cur;
                primes.push_back(cur);
            }
        }
        if(b != 1) primes.push_back(b);
        // db(primes.size());
        sort(primes.begin(), primes.end());
        set<ll> divisors;
        divisors.insert(1);
        for(auto p : primes){
            vector<ll> add;
            for(auto div : divisors) add.push_back(p * div);
            for(auto div : add) divisors.insert(div);
        }
        // db(divisors.size());
        // for(auto d : divisors) cout << d << " ";
        // cout << "\n";
        a = old_a, b = old_b;
        for(auto mult : divisors){
            ll inv_mult = (a * b) / mult;
            if((c / (inv_mult) - a / (inv_mult)) > 0){
                par_ans.st = inv_mult * ((c) / inv_mult);
                if((d / (mult) - b / (mult)) > 0){
                    ok = true;
                    par_ans.nd = mult * ((d) / mult);
                    break;
                }
            }
        }
        if(ok) cout << par_ans.st << " " << par_ans.nd << "\n";
        else cout << "-1 -1\n";
    }
    return 0;
}