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
const int N = 5e4+5;

int n, ps[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ps[i]);
        ps[i] += ps[i-1];
    }

    for(int i=1;i<=n;i++){
        int pos = i;
        int ans = 0;
        for(int j=1;pos <= n;j++){
            int nxt = min(n+1,pos + 3*j);
            ans += max(0,ps[nxt-1] - ps[pos-1]);
            pos = nxt;
        }
        printf("%d\n",ans);
    }
    return 0;
}