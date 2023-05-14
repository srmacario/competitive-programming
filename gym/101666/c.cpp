#include <bits/stdc++.h>
 
using namespace std;
 
#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;
const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5;
 
ll n;
set <ll> num;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<ll> old,now;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        old.pb(x);
        num.insert(old[i]);
    }
    bool ok = true;
    ll last = 0;
    while(ok){
        for(int i=1;i<old.size();i++){
            ll g = gcd(old[i],old[i-1]);
            num.insert(g);
            if(g != last) now.pb(g), last = g;
        }
        if(now.size() <= 1) ok = false;
        old = now;
        now.clear();
    }
    num.insert(1);
    cout << num.size() << "\n";
    return 0;
}