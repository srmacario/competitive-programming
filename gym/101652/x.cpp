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
    cout << n << ":\n";
    set<pii> ans;
    for(int i = (n + 1)/2; i >= 2; i--){
        if(!(n % i)) ans.insert({i, i});
        if(!((n + i - 1) % (2 * i - 1))) ans.insert({i, i - 1});
        if(!(n % (2 * i - 1))) ans.insert({i, i - 1});
    }
    for(auto p : ans) cout << p.st << "," << p.nd << "\n";
    return 0;
}