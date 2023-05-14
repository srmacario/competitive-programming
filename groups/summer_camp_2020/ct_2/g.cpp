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

ll k;
map <ll,ll> pr,gr;

void factorize(ll n) {
    for(ll i = 2; i*i <= n; i++){
        ll pot = 0;
        while ((n % i) == 0){
          pot++;
          n /= i;
        }  
        if (pot > 0){
            if(!pr.count(i)) pr[i] = 0;
            pr[i] = pr[i] | (1ll<<pot);
        }
    }
    if(n > 1){
        if(!pr.count(n)) pr[n] = 0;
        pr[n] = pr[n] | (1ll<<1);
    }
}

ll grundy(ll mask){
    if(mask <=1) return 0;
    if(gr.count(mask)) return gr[mask];
    set <ll> possible;
    for(ll i = 1;(1ll << i) <= mask;i++){
        ll now = mask & ((1ll << i) - 1);
        ll shift = (mask ^ now) >> i;
        possible.insert(grundy(now | shift));
    }
    ll ans = 0;
    for(auto it : possible){
        if(it != ans) break;
        ans++;
    }
    return gr[mask] = ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    for(int i=1;i<=k;i++){
        ll x;
        cin >> x;
        factorize(x);
    }
    ll ans = 0;
    for(auto it : pr){
        ans = ans^grundy(it.nd);
    }
    cout << (ans ? "Mojtaba\n" : "Arpa\n");
    return 0;
}