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
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string x,a,b;
        a.resize(n), b.resize(n);
        cin >> x;
        ll last = 0;
        for(ll i=0;i<n;i++){
            if(x[i] == '2'){
                if(!last) b[i] = '1', a[i] = '1';
                else b[i] = '0', a[i] = '2';
            }
            else if(x[i] == '0') a[i] = b[i] = '0';
            else{
                if(!last) b[i] = '1', a[i] = '0', last = '1';
                else b[i] = '0', a[i] = '1';
            }
        }
        cout << b << "\n" << a << "\n";
    }
    return 0;
}