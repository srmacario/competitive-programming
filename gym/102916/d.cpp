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
ld one, two, p[N], last[N];

int main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i%2 and n%2) or (!(i%2) and !(n%2))){
                if(i > j) continue;
                if(i == j) p[j] = 1;
            }
            else{
                // db((((ld)j - 1)/((ld)i))*p[j-1] _ (((ld)i - j)/((ld)i))*p[j]);
                p[j] = (((ld)j - 1)/((ld)i))*last[j-1] + (((ld)i - j)/((ld)i))*last[j];
            }
        }
        for(int j = 1; j <= n; j++){
            // cout << p[j] << " ";
            last[j] = p[j];
        }
        // cout << "\n";
    }
    for(int i = 1; i <= n; i++) one += p[i]*a[i], two += (1 - p[i])*a[i];
    cout << setprecision(12) << fixed << one << " " << two << "\n";
    return 0;
}