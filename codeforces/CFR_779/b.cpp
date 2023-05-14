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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll fat[N];
    fat[0] = 1;
    for(int i = 1; i < N; i++) fat[i] = (i * fat[i - 1]) % MOD;
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n%2) cout << "0\n";
        else cout << (fat[n / 2] * fat[n / 2]) % MOD << "\n";
    }
    return 0;
}