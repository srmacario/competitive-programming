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
        ll ans = 0;
        vector <ll> a(3), b(3);
        cin >> a[0] >> a[1] >> a[2];
        cin >> b[0] >> b[1] >> b[2];
        
        if(a[0] >= b[2]) {a[0] -= b[2], b[2] = 0;}
        else{b[2] -= a[0], a[0] = 0;}    
        if(a[0] >= b[0]) {a[0] -= b[0], b[0] = 0;}
        else{b[0] -= a[0], a[0] = 0;}
        if(a[0] >= b[1]) {a[0] -= b[1], b[1] = 0;}
        else{b[1] -= a[0], a[0] = 0;}

        if(b[0] >= a[1]) {b[0] -= a[1], a[1] = 0;}
        else{a[1] -= b[0], b[0] = 0;}
        if(b[0] >= a[2]) {b[0] -= a[2], a[2] = 0;}
        else{a[2] -= b[0], b[0] = 0;}
        //cout << a[0] << " " << a[1] << " "  << a[2] << "\n" ;
        //cout << b[0] << " " << b[1] << " "  << b[2] << "\n" ;
        
        //cout << a[0] << " " << a[1] << " "  << a[2] << "\n" ;
        //cout << b[0] << " " << b[1] << " "  << b[2] << "\n" ;
        for(int i=1;i<=2;i++){
            ll mn = min(a[i],b[i]);
            a[i] -= mn, b[i] -= mn;
        }
        ans += 2*(a[2] - b[2]);
        cout << ans << "\n";
    }
    return 0;
}