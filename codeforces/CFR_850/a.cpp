#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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
        int n;
        cin >> n;
        int c[2] = {0};
        c[0] += 1;
        n -= 1;
        int p = 1;
        for(int i = 2; n; i++){
            if(n - i > 0) c[p] += i, n -= i;
            else{
                c[p] += n;
                break;
            }
            i++;
            if(n - i > 0) c[p] += i, n -= i;
            else{
                c[p] += n;
                break;
            }
            p ^= 1;
        }
        cout << c[0] << " " << c[1] << "\n";
    }
    return 0;
}