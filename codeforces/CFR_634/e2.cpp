#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi ps[205], pos[205];
        for(int i=0;i<205;i++) {
            for(int j=0;j<=n;j++){
                ps[i].pb(0);
            }
        }
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            pos[x].pb(i);
            for(int j=0;j<205;j++){
                if(j!=x) ps[j][i] = ps[j][i-1];
                else ps[j][i] = ps[j][i-1] + 1;
            }
        }
        int ans = 0;
        for(int i=1;i<205;i++){
            int dist = pos[i].size();
            if(!dist) continue;
            ans = max(ans,dist);
            for(int j=0;j<dist/2;j++){
                for(int k=1;k<205;k++){
                    if(i == k) continue;
                    if(!pos[k].size()) continue;
                    int ini = pos[i][j], fim = pos[i][dist-j-1];
                    int pre = ps[k][fim] - ps[k][ini];
                    int sz = 2*(j+1) + pre;
                    ans = max(ans,sz);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}