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
const int N = 2e5+5;

int x[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, vector<int>> m;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
            m[x[i]].push_back(i);
        }
        pair<pii, pii> ans = {{0, 0}, {0, 0}};
        for(auto it : m){
            piii maxsofar = {0, {0, 0}}, maxnow = {0, {0, 0}};
            for(int i = 0; i < it.nd.size(); i++){
                maxnow.st++;
                if(maxnow.nd.st) maxnow.st -= (it.nd[i] - it.nd[i - 1] - 1);
                else maxnow.nd.st = it.nd[i];
                maxnow.nd.nd = it.nd[i];
                maxnow = max({1, {it.nd[i], it.nd[i]}}, maxnow);
                maxsofar = max(maxsofar, maxnow);
            }
            pair<pii, pii> tmp = {{maxsofar.st, it.st}, maxsofar.nd};
            ans = max(ans, tmp);
        }
        cout << ans.st.nd << " " << ans.nd.st << " " << ans.nd.nd << "\n";
    }
    return 0;
}