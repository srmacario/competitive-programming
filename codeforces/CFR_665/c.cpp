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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

map<ll,ll> pos;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        vector <pll> b(n);
        ll mn = LINF;
        for(int i=0;i<n;i++){
            cin >> a[i];
            b[i] = {a[i],i};
            mn = min(mn,a[i]);
        }
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++){
            pos[b[i].nd] = i;
        }
        bool ok = true;
        for(int i=0;i<n;i++){
            if(a[i]%mn){
                if(i != pos[i]){
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
        pos.clear();
    }
    return 0;
}