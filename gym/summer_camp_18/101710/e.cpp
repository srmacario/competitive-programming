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

string s, t;
int n;

vi Z (string &q) {
    vi z(q.size());
    for (int i = 1, l = 0, r = 0, n = q.size(); i < n; i++) {
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i + z[i] < n and q[z[i]] == q[z[i] + i]) z[i]++;
        if (i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    t = s;
    n = s.size();
    reverse(t.begin(), t.end());
    s += "$" + t;
    //cout << s << "\n";
    vi ans = Z(s);
    int mx = 1;
    for(int i=n+1;i<=2*n;i++){
        //db(ans[i] _ (2*n-i+1)/2);
        if(ans[i] >= (2*n-i+1)/2) mx = max(mx,(2*n-i+1));
    }
    cout << mx << "\n";
    return 0;
}