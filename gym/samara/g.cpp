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

ll c[N];

int main(){
    int n;
    ll s;
    scanf("%d%lld", &n, &s);
    c[0] = 1;
    for(int i = 1; i <= n; i++){
        ll x;
        scanf("%lld", &x);
        if(c[i-1] * x <= s){
            c[i] = x*c[i-1];
        }
        else c[i] = INF;
    }
    int cnt = 0;
    for(int i = n; i >= 0; i--){
        cnt += s/c[i];
        s = (s%c[i]);
        if(s == 0) break;
    }
    printf("%d\n", cnt);
    return 0;
}