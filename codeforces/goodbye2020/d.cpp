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

int ing[N];
ll ans[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, root, cnt = 1;
        cin >> n;
        vi w(n+5);
        for(int i=1;i<=n;i++){
            cin >> w[i];
            ans[1] += w[i];
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin >> u >> v;
            ing[u]++, ing[v]++;
        }
        vector <pll> nodes;
        for(int i=1;i<=n;i++) nodes.pb({w[i],ing[i]});
        sort(nodes.begin(),nodes.end(), greater<pll>());
        if(n > 2){
            for(auto v : nodes){
                while(v.nd > 1){
                    ans[cnt+1] = ans[cnt] + v.st;
                    cnt++;
                    v.nd--;
                }
            }            
        }
        for(int i=1;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++) ing[i] = ans[i] = 0;
    }
    return 0;
}