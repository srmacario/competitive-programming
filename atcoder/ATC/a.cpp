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

int n;
map <pii,ll> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        double x;
        cin >> x;
        ll num = llround(x*1e9), cnt2 = 0, cnt5 = 0;
        while(!(num%2)){
            num/=2;
            cnt2++;                 
        }               
        while(!(num%5)){
            num/=5;
            cnt5++;
        }
        m[{cnt2,cnt5}]++;
    }
    ll ans = 0;
    for(auto a: m){
        for(auto b: m){
            if(a.st.st + b.st.st >= 18 and a.st.nd + b.st.nd >= 18){
                if(a < b) ans += a.nd*b.nd;
                else if (a == b) ans += (a.nd*(b.nd - 1))/2;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}