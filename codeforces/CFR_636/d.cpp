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
        vi a,ps;
        int n,k;
        cin >> n >> k;
        a.resize(n+5);
        ps.resize(2*k+5);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n/2;i++){
            ps[0] += 2;
            ps[min(a[i],a[n-i+1]) + 1] -= 1;
            ps[k + max(a[i],a[n-i+1]) + 1] += 1;
            ps[2*k+1] -= 2;
            int sum = a[i] + a[n-i+1];
            if(sum > min(a[i],a[n-i+1]) and sum <= k + max(a[i],a[n-i+1])) ps[sum]-=1, ps[sum+1]+=1;
            else ps[sum]-= 2, ps[sum+1]+=2;
        }
        int ans = INF;
        for(ll i=1;i<=2*k;i++){
            ps[i] += ps[i-1];
            ans = min(ans,ps[i]);
        }
        cout << ans << "\n";
        a.clear(), ps.clear();
    }
    return 0;
}