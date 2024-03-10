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

int k;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> k;
    vector<vector<char>> chars(k);
    for(int i = 0; i < s.size(); i++) chars[i % k].push_back(s[i]);
    for(int i = 0; i < k; i++) sort(chars[i].begin(), chars[i].end());
    for(int i = 0; i < s.size(); i++){
        cout << chars[i%k][i/k];
    }
    cout << "\n";
    return 0;
}