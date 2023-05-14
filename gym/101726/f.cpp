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
        int n,w,s,l = 0;
        cin >> n >> w >> s;
        vi h(n);
        for(int i=0;i<n;i++){
            cin >> h[i];
            if(h[i] == 0) l = i;
        }
        ld langle = 0, rangle = 0, ans;
        for(int i=0;i<l;i++){
            ld x = (l-i)*(w+s), y = h[i];
            ld tg = -y/x;
            ld angle =  - atan(tg);
            langle = max(langle,angle);
        }
        for(int i=l+1;i<n;i++){
            ld x = (i-l)*(w+s), y = h[i];
            ld tg = y/x;
            ld angle = atan(tg);
            rangle = max(rangle,angle);
        }
        ans = PI - rangle - langle;
        cout << fixed << setprecision(10) << (960) * (ans/PI) << "\n";
    }
    return 0;
}