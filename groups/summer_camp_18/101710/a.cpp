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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi z(n), ans(n);
    for(int i=0;i<n;i++) cin >> z[i];
    for(int i=0;i<n;i++){
        if(z[i]) ans[i+z[i]-1] = max(ans[i+z[i]-1],z[i]);
    }
    int cur = 0;
    for(int i=n-1;i>=0;i--){
        if(ans[i] > cur) cur = ans[i];
        ans[i] = cur;
        cur = max(0,cur-1);
    }
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}