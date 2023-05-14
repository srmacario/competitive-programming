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

vector<int> zfunction(const string& s){
  vector<int> z (s.size());
  for (int i = 1, l = 0, r = 0, n = s.size(); i < n; i++){
    if (i <= r) z[i] = min(z[i-l], r - i + 1);
    while (i + z[i] < n and s[z[i]] == s[z[i] + i]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,rev;
    cin >> s;
    rev = s;
    reverse(rev.begin(),rev.end());
    string tmp = rev + "$" + s;
    vi ans = zfunction(tmp);
    int pos = 0;
    for(int i = s.size()+1;i<tmp.size();i++){
        if(ans[i] == tmp.size() - i) break;
        pos++;
    }
    for(int i=pos-1;i>=0;i--) s+= s[i];
    cout << s << "\n";
    return 0;
}