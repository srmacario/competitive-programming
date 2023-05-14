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
        vector<int> c(n + 5), ans(n + 5), chn(n + 5);
        int ini = 1;
        for(int i = 1; i <= n; i++) cin >> c[i];
        //init
        while(ini <= n and !c[ini]) ans[ini++] = 0;
        ans[ini] = 1;

        //iterate
        for(int l = ini, r = ini; l <= n and r <= n; l++){
            int sum = r - chn[l];
            int dif = c[l] - sum;
            while(dif--){
                ans[++r] = 1;
                if(r == n) break;
            }
            ans[++r] = 0;
            chn[r] = r - 1;
            if(r == n) break;
        }
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}