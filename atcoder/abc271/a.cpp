#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int dig[2];
    dig[0] = n/16, dig[1] = n%16;
    if(dig[0] > 9) cout << (char)((dig[0] - 9) + 'A' - 1);
    if(dig[0] <= 9) cout << dig[0];
    if(dig[1] > 9) cout << (char)((dig[1] - 9) + 'A' - 1);
    if(dig[1] <= 9) cout << dig[1];
    cout << "\n";
    return 0;
}