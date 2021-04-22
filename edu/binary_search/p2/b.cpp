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

int n, k, a[N];

// bool ok(ll m){
//     return (m/w)*(m/h) >= n;
// }

// ll binS(ll l, ll r){
//     while(l < r){
//         ll m = (l + r)/2;
//         if(!ok(m)) l = m + 1;
//         else r = m;
//     }
//     return l;
// }

// int main(){
//     scanf("%lld%lld%lld",&w, &h, &n);
//     ll r = 1;
//     while(!ok(r)) r *= 2;
//     printf("%lld\n", binS(0,r));
//     return 0;
// }