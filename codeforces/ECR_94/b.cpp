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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll ptot,ftot;
        ll tot = 0;
        cin >> ptot >> ftot;
        pll swo, war;
        cin >> swo.nd >> war.nd;
        cin >> swo.st >> war.st;
        ll cp = 0, cf = 0;
        if(swo.st > war.st) swap(swo,war);
        for(ll i=0;i<=swo.nd;i++){
            ll ans = 0, p = ptot, f = ftot, cur = 0;
            pll s = swo, w = war;
            if(i*s.st > p) break;
            ans += i;
            p -= i*s.st, s.nd -= i;
            cur = min(p/w.st,w.nd);
            w.nd -= cur, ans += cur, p -= cur*w.st;
            cur = min(f/s.st,s.nd);
            s.nd -= cur, ans += cur, f -= cur*s.st;
            cur = min(f/w.st,w.nd);
            w.nd -= cur, ans += cur, f -= cur*w.st;
            tot = max(ans,tot);
        }
        cout << tot << "\n";
    }
    return 0;
}