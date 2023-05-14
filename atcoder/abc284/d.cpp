#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7+5;

int t;
ull n, p, q;
long double x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        p = q = 0;
        cin >> n;
        for(ll i = 2; i < N; i++){
            if(!(n % i)){
                q = i;
                n /= i;
                if(!(n % i)){
                    p = q;
                    q = n / i;
                }
                break;
            }
        }
        if(p and q){
            cout << p << " " << q << "\n";
            continue;
        }
        x = n;
        ull root = sqrt(x);
        ull l = 2, r = n / 2;
        while(l < r){
            ull mid = (l + r) / 2;
            if(mid < n / mid) l = mid + 1;
            else r = mid;
        }
        cout << l << " " << q << "\n";
    }
    return 0;
}