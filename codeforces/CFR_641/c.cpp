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
const int N = 2e6+10;

ll cmp[N], a[N], n, total;
vector <pair<ll,pll>> pr;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        ll minst = LINF, minnd = LINF, cnt = 0;
        for (ll j = i; j < N; j += i){
            cmp[j] = 1;
            if(a[j]){
                cnt+=a[j];
                ll temp = 0, aux = j;
                while(!(aux%i)){
                    temp++;
                    aux/=i;
                }
                if(temp < minnd and temp >= minst) minnd = temp;
                else if(temp < minst){
                    if(a[j] > 1) minnd = minst = temp;
                    minnd = minst, minst = temp;
                }
            }
        }
        if(n - cnt >= 2) minnd = minst = 0;
        if(n - cnt == 1) minnd = minst, minst = 0;
        pr.pb({i,{minst,minnd}});
    }
}

ll fexp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b);
        b = (b*b);
        e >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    total = n;
    int x;
    for(int i=1;i<=n;i++){
        cin >> x;
        if(a[x]) total--;
        a[x]++;
    }
    if(total == 1){
        cout << x << "\n";
        return 0;
    }
    primes();
    ll ans = 1;
    for(int i=0;i<pr.size();i++){
        ll e = pr[i].nd.nd;
        if(e and e!= LINF) ans *= fexp(pr[i].st,e);
    }
    cout << ans << "\n";
    return 0;
}