#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define dbs(x) cerr << x << endl;
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e7 + 5;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n % 2){
        cout << "0\n";
        return 0;
    }
    ll last = 1, cur = 3;
    for(int i = 4; i <= n; i += 2){
        ll new_cur = (4 * cur) % MOD;
        new_cur = (new_cur - last + MOD) % MOD;
        last = cur;
        cur = new_cur;
    }
    cout << cur << "\n";
    return 0;
}