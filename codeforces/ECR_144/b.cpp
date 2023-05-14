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
        string a, b;
        cin >> a >> b;
        pair<int, string> ans;
        for(int l = 0; l < a.size(); l++){
            string subs;
            if(l != a.size() - 1){
                subs = a.substr(l, (2));
                if(b.find(subs) != string::npos){
                    ans = max({ans, make_pair(2, subs)});
                }
            }
            subs = a.substr(l, (1));
            if(b.find(subs) != string::npos){
                ans = max({ans, make_pair(1, subs)});
            }
        }
        if(ans.st > 1){
            cout << "YES\n";
            cout << "*" << ans.nd << "*\n";
            continue;
        }
        if(ans.st == 1){
            if(a[0] == b[0]){
                cout << "YES\n";
                cout << a[0] << "*\n";
                continue;
            }
            if(a.back() == b.back()){
                cout << "YES\n";
                cout << "*" << a.back() << "\n";
                continue;
            }
        }
        cout << "NO\n";
    }
    return 0;
}