#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
int N = 1e7;

ll ans(ll v){
    ll r, h;
    v = (v * 31 + 'a')%MOD;
    r = (7 * v)%MOD;
    if(r > 1000000000) h = MOD + N - r;
    else h = ((r - 1)/N + 1)*N - r;
    return h;
}

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll v, t1, t2;
    string r = "a";
    cin >> v;
    //first hash
    cout << "a ";
    t1 = ans(v);
    cout << t1 << "\n";
    //cout << H(v, r, t1) << "\n";
    //second hash
    cout << "a ";
    t2 = ans(H(v, r, t1));
    cout << t2 << "\n";
    //cout << H(H(v, r, t1), r, t2) << "\n";
    return 0;
}