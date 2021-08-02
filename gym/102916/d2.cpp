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
const int N = 5e3+5;

ll n, a[N];
ld one, two, cur[N], pre_cur[N];

int main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1, greater<ll>());
    one = a[1];
    cur[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = i/2 + 1; j <= n; j++){
            ld p = 0;
            if(i%2){
                if(j > i) continue;
                ld tmp = (1 - cur[j]);
                if(j == i) tmp = 1;
                p = (tmp);
                one += p * a[j];
            }
            else{
                p = (1 - cur[j])/((ld)n - i + 1);
                two += p * a[j];
            }
            cur[j] = p;
        }
        // pre_cur[(i+1)/2] = 1;
        // for(int j = (i+1)/2 + 1; j <= n; j++) pre_cur[j] = cur[j]*pre_cur[j-1];
    }
    cout << setprecision(12) << fixed << one << " " << two << "\n";
    return 0;
}