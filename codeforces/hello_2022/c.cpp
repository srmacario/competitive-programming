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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi ant(n + 5), vis(n + 5), ans(n + 5), nxt(n + 5);
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            int cur = i;
            int cnt = sum;
            while(true){
                int x;
                cout << "? " << i << endl;
                cin >> x;
                sum++;
                ant[x] = cur;
                nxt[cur] = x;
                cur = x;
                if(vis[x]) break;
                vis[x] = 1;
            }
            while(cnt--){
                cur = ant[cur];
            }
            while(!ans[cur]){
                ans[cur] = nxt[cur];
                cur = nxt[cur];
            }
        }
        cout << "! ";
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}