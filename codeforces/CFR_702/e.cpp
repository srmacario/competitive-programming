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
const int N = 2e5+5;

int n;
pll a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++){
            a[i].nd = i;
            cin >> a[i].st;
        }        
        sort(a,a+n+1);
        for(int i=1;i<=n;i++){
            a[i].st += a[i-1].st;
        }
        vi ans;
        ans.pb(a[n].nd);
        for(int i=n-1;i>=1;i--){
            if(a[i].st < a[i+1].st - a[i].st) break;
            ans.pb(a[i].nd);
        }
        cout << ans.size() << "\n";
        sort(ans.begin(),ans.end());
        for(auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}