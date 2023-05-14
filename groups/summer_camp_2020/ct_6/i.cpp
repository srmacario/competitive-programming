#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ans = INF, ansmin, t;
    vi lis;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        lis.pb(x);
    }
    cin >> t;
    for(int i=0;i<n;i++){
        if(ans > t%lis[i]) ans = t%lis[i], ansmin = lis[i];
    }
    cout << ansmin << "\n";
    return 0;
}