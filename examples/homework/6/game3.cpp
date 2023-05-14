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
const int N = 1e5+5;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll n;
        scanf("%lld", &n);
        bool ok = true;
        if(!(n&1)) ok = false;
        else{
            int cnt = 1;
            n--;
            while(n > 3){
                n >>= 1;
                cnt++;
                if(n&1 and cnt&1){
                    ok = false;
                    break;
                }
            }
            if(n <= 3){
                if(cnt&1) ok = true;
                else ok = false;
            }
        }
        printf("%s\n", (ok ? "Ivica" : "Marica"));
    }
    return 0;
}