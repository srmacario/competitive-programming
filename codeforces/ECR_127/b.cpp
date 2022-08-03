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
        vector<int> x(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        int sr = 0, sl = 0;
        bool ok = true;
        for(int i = 1; i < n; i++){
            if(x[i] == x[i - 1] + 1) continue;
            if(!sr){
                x[i - 1]++;
                sr = 1;
            }
            if(x[i] > x[i - 1] + 1){
                x[i]--;
            }
            if(x[i] > x[i - 1] + 1) ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}