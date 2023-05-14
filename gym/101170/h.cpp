#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;
string s1, s2;

ll pos(string& s, int idx = 0) {
    if (idx == n - 1) {
        if (s[idx] == '1') return 2;
        return 1;
    }
    int val = n - idx;
    ll x = pos(s, idx + 1);
    if (s[idx] == '1') x = (1ll << ll(val)) + 1 - x;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s1 >> s2;
    cout << pos(s2) - pos(s1) - 1 << "\n";
    return 0;
}
