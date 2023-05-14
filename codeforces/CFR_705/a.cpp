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
        int n, k;
        scanf("%d%d", &n, &k);
        vi ans;
        for(int i = 1; i <= n; i++){
            if(i >= (k+1)/2 and i < k) ans.pb(i);
            else if (i > k) ans.pb(i);
        }
        printf("%ld\n", ans.size());
        for(auto x : ans) printf("%d ", x);
        printf("\n");
    }
    return 0;
}