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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<string> grid;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            grid.pb(s);
        }
        int cnt = 0;
        vector <pii> ans;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-2;j++){
                int aux = 0;
                if(grid[i][j]-'0' or grid[i+1][j]-'0'){
                    if(grid[i][j]-'0') grid[i][j] = (grid[i][j] - '0')^1 + '0', aux++, ans.pb({i+1,j+1});
                    if(grid[i+1][j]-'0') grid[i+1][j] = (grid[i+1][j] - '0')^1 + '0', aux++, ans.pb({i+2,j+1});
                }
                else continue;
                if(aux < 2){
                    grid[i][j+1] = (grid[i][j+1] - '0')^1 + '0';
                    ans.pb({i+1,j+2});
                    grid[i+1][j+1] = (grid[i+1][j+1] - '0')^1 + '0';
                    ans.pb({i+2,j+2});
                }
                else{
                    if(grid[i][j+1]-'0') grid[i][j+1] = (grid[i][j+1] - '0')^1 + '0', aux++, ans.pb({i+1,j+2});
                    else grid[i+1][j+1] = (grid[i+1][j+1] - '0')^1 + '0', aux++, ans.pb({i+2,j+2});
                }
                cnt++;
            }
        }
        cout << cnt << "\n";
        for(int i=0;i<ans.size();i+=3){
            cout << ans[i].st << " " << ans[i].nd << " ";
            cout << ans[i+1].st << " " << ans[i+1].nd << " ";
            cout << ans[i+2].st << " " << ans[i+2].nd << "\n";
        }
        
        for(int i=0;i<n;i++){
            cout << grid[i] << "\n";
        }
        cout << "\n";
    }
    return 0;
}