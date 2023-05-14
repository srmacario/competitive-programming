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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(!(n % 2)){
            cout << "-1\n";
            continue;
        }
        vector<int> ans;
        while(n > 3){
            if((1 << 1) & n){
                ans.push_back(2);
            }
            else{
                ans.push_back(1);
            }
            n >>= 1;
            n |= 1;
        }
        if(n == 3) ans.push_back(2);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(auto a : ans) cout << a << " ";
        cout << "\n";
    }
    return 0;
}