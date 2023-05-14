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

map<ll, int> f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k, n = 0;
    cin >> k;
    for(ll i = 2; i * i <= k; i++){
        while(!(k % i)){
            f[i]++;
            k /= i;
        }
    }
    if(k != 1) f[k]++;
    for(auto p : f){
        // db(p.st _ p.nd);
        ll cnt = 0, tmp = 0;
        for(tmp = p.st; cnt < p.nd; tmp += p.st){
            ll mult = tmp;
            while(!(mult % p.st)){
                cnt++;
                mult /= p.st;
            }
            if(cnt >= p.nd) break;
        }
        n = max(n, tmp);
    }
    cout << n << "\n";
    return 0;
}