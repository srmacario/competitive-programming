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
    int h, w, k, ans = INF;
    cin >> h >> w >> k;
    vector<string> grid(h);
    for(int i = 0; i < h; i++)
        cin >> grid[i];
    
    for(int i = 0; i < h; i++){
        if(w < k) break;
        int r = 0, cur = 0;
        for(int l = 0; l < w and r < w; l++){
            while((r - l + 1) <= k and r < w){
                if(grid[i][r] == 'x') break;
                cur += (grid[i][r] != 'o');
                r++;
            }
            if(r - l + 1 > k) ans = min(ans, cur);
            else if(r < w and grid[i][r] == 'x'){
                r = l + 1;
                cur = 0;
                continue;
            }
            cur -= (grid[i][l] != 'o');
        }
    }
    
    for(int j = 0; j < w; j++){
        if(h < k) break;
        int r = 0, cur = 0;
        for(int l = 0; l < h and r < h; l++){
            while((r - l + 1) <= k and r < h){
                if(grid[r][j] == 'x') break;
                cur += (grid[r][j] != 'o');
                r++;
            }
            if(r - l + 1 > k) ans = min(ans, cur);
            else if(r < h and grid[r][j] == 'x'){
                r = l + 1;
                cur = 0;
                continue;
            }
            cur -= (grid[l][j] != 'o');
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}