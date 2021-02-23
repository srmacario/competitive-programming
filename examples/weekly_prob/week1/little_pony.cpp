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

int n,m;
ld prob[N];

ld fexp (ld b, int e) {
    ld ans = 1;
    while (e) {
        if (e&1) ans = (ans*b);
        b = (b*b);
        e >>= 1;
    }
    return ans;
}

int main(){
    scanf("%d%d",&m,&n);
    ld ans = 0;
    for(int i=1;i<=m;i++){
        ld b = (ld)i/m;
        prob[i] = fexp(b,n);
        ans += i*(prob[i] - prob[i-1]);
    }
    printf("%.10LF\n",ans);
    return 0;
}