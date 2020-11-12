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
const int N = 2e6+5;

int cmp[N];
vi pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

map<int, int> factorize(int n) {
    map<int, int> fact;
    for(int i = 0; pr[i]*pr[i] <= n; i++)
        while (n % pr[i] == 0) fact[pr[i]]++, n /= pr[i];
    if (n > 1) fact[n]++;
    return fact;
}

map <int, int> f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primes();
    for(int i=1;i<=N;i++){
        f = factorize(i);
        ll ans = 0;
        map<int,int> div;
        div[1] = 1;
        for(auto u: f){
            for(int j=0;j<u.nd;j++){
                map <int,int> aux;
                aux = div;
                for(auto v: div){
                    aux[v.st*u.st]++;
                }
                div = aux;
            }
        }
        for(auto u : div) ans += u.st;
        if(i == ans-i) cout << i << "\n";
    }
    return 0;
}