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
            for(int j=0;j<m;j++){
                if(grid[i][j]-'0'){
                    grid[i][j] = (grid[i][j] - '0')^1 + '0';
                    ans.pb({i+1,j+1});
                    grid[i+1][j] = (grid[i+1][j] - '0')^1 + '0';
                    ans.pb({i+2,j+1});
                    if(j!=m-1){
                        grid[i+1][j+1] = (grid[i+1][j+1] - '0')^1 + '0';
                        ans.pb({i+2,j+2});
                    }
                    else{
                        grid[i+1][j-1] = (grid[i+1][j-1] - '0')^1 + '0';
                        ans.pb({i+2,j});
                    }
                    cnt++;
                }
            }
        }
        //db(ans.size());
        for(int j=0;j<m-1;j++){
            int aux = 0;
            if(grid[n-1][j]-'0' or grid[n-2][j]-'0'){
                if(grid[n-1][j]-'0') grid[n-1][j] = (grid[n-1][j] - '0')^1 + '0', aux++, ans.pb({n,j+1});
                if(grid[n-2][j]-'0') grid[n-2][j] = (grid[n-2][j] - '0')^1 + '0', aux++, ans.pb({n-1,j+1});
            }
            else continue;
            if(grid[n-2][j+1]-'0' or aux < 2){
                grid[n-2][j+1] = (grid[n-2][j+1] - '0')^1 + '0';
                aux++;
                ans.pb({n-1,j+2});
            }
            if(grid[n-1][j+1]-'0' or aux < 3){
                grid[n-1][j+1] = (grid[n-1][j+1] - '0')^1 + '0';
                aux++;
                ans.pb({n,j+2});
            }
            cnt++;
        }
        //db(ans.size());
        if(grid[n-1][m-1] == '1' and grid[n-2][m-1] == '0'){
            grid[n-1][m-1] = (grid[n-1][m-1] - '0')^1 + '0', ans.pb({n,m});
            grid[n-1][m-2] = (grid[n-1][m-2] - '0')^1 + '0', ans.pb({n,m-1});
            grid[n-2][m-2] = (grid[n-2][m-2] - '0')^1 + '0', ans.pb({n-1,m-1});

            grid[n-1][m-1] = (grid[n-1][m-1] - '0')^1 + '0', ans.pb({n,m});
            grid[n-2][m-1] = (grid[n-2][m-1] - '0')^1 + '0', ans.pb({n-1,m});
            grid[n-2][m-2] = (grid[n-2][m-2] - '0')^1 + '0', ans.pb({n-1,m-1});

            grid[n-1][m-1] = (grid[n-1][m-1] - '0')^1 + '0', ans.pb({n,m});
            grid[n-2][m-1] = (grid[n-2][m-1] - '0')^1 + '0', ans.pb({n-1,m});
            grid[n-1][m-2] = (grid[n-1][m-2] - '0')^1 + '0', ans.pb({n,m-1});
            cnt+=3;
        }
        else if(grid[n-1][m-1] == '1' and grid[n-2][m-1] == '1'){
            grid[n-1][m-1] = (grid[n-1][m-1] - '0')^1 + '0', ans.pb({n,m});
            grid[n-1][m-2] = (grid[n-1][m-2] - '0')^1 + '0', ans.pb({n,m-1});
            grid[n-2][m-2] = (grid[n-2][m-2] - '0')^1 + '0', ans.pb({n-1,m-1});
            
            grid[n-2][m-1] = (grid[n-2][m-1] - '0')^1 + '0', ans.pb({n-1,m});
            grid[n-1][m-2] = (grid[n-1][m-2] - '0')^1 + '0', ans.pb({n,m-1});
            grid[n-2][m-2] = (grid[n-2][m-2] - '0')^1 + '0', ans.pb({n-1,m-1});
            cnt+=2;
        }
        else if(grid[n-1][m-1] == '0' and grid[n-2][m-1] == '1'){
            grid[n-2][m-1] = (grid[n-2][m-1] - '0')^1 + '0', ans.pb({n-1,m});
            grid[n-1][m-2] = (grid[n-1][m-2] - '0')^1 + '0', ans.pb({n,m-1});
            grid[n-2][m-2] = (grid[n-2][m-2] - '0')^1 + '0', ans.pb({n-1,m-1});

            grid[n-1][m-1] = (grid[n-1][m-1] - '0')^1 + '0',ans.pb({n,m});
            grid[n-2][m-1] = (grid[n-2][m-1] - '0')^1 + '0', ans.pb({n-1,m});
            grid[n-2][m-2] = (grid[n-2][m-2] - '0')^1 + '0', ans.pb({n-1,m-1});

            grid[n-1][m-1] = (grid[n-1][m-1] - '0')^1 + '0',ans.pb({n,m});
            grid[n-2][m-1] = (grid[n-2][m-1] - '0')^1 + '0', ans.pb({n-1,m});
            grid[n-1][m-2] = (grid[n-1][m-2] - '0')^1 + '0', ans.pb({n,m-1});
            cnt+=3;
        }
        //db(ans.size());
        cout << cnt << "\n";
        for(int i=0;i<ans.size();i+=3){
            cout << ans[i].st << " " << ans[i].nd << " ";
            cout << ans[i+1].st << " " << ans[i+1].nd << " ";
            cout << ans[i+2].st << " " << ans[i+2].nd << "\n";
        }
        /*for(int i=0;i<n;i++){
            cout << grid[i] << "\n";
        }*/
    }
    return 0;
}