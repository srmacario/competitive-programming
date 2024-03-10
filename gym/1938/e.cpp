#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define endl '\n'

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
        vector<pair<pii, int>> ans;
        vector<vector<int>> grid(n + 5, vector<int>(n + 5));
        //0 row 1 col
        vector<set<int>> num[2];
        num[0].resize(n + 1), num[1].resize(n + 1);
        vector<int> not_rep[2];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> grid[i][j];
                num[0][i].insert(grid[i][j]);
                num[1][j].insert(grid[i][j]);
            }
        }
        //see not repeated rows and columns
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 2; j++){
                if(num[j][i].size() == n) not_rep[j].push_back(i);
            }
        }
        //match not repeated row with column
        while(not_rep[0].size() and not_rep[1].size()){
            //find a common value to switch grid[i, j]
            int i = not_rep[0].back();
            int j = not_rep[1].back();
            int val = (grid[i][j]) % n + 1;
            num[0][i].erase(grid[i][j]), num[1][j].erase(grid[i][j]);
            grid[i][j] = val;
            not_rep[0].pop_back(), not_rep[1].pop_back();
            ans.push_back({{i, j}, val});
        }
        //maybe there is something left in row or column
        while(not_rep[0].size()){
            int i = not_rep[0].back();
            int val = 0;
            for(int j = 2; j <= n; j++){
                if(num[1][1].count(grid[i][j])){
                    val = grid[i][j];
                    break;
                }
            }
            if(!val) val = (grid[i][1]) % n + 1;
            grid[i][1] = val;
            ans.push_back({{i, 1}, grid[i][1]});
            not_rep[0].pop_back();
        }
        while(not_rep[1].size()){
            int j = not_rep[1].back();
            int val = 0;
            for(int i = 2; i <= n; i++){
                if(num[0][1].count(grid[i][j])){
                    val = grid[i][j];
                    break;
                }
            }
            if(!val) val = (grid[1][j]) % n + 1;
            grid[1][j] = val;
            ans.push_back({{1, j}, grid[1][j]});
            not_rep[1].pop_back();
        }
        cout << ans.size() << "\n";
        for(auto a : ans){
            cout << a.st.st << " " << a.st.nd << " " << a.nd << "\n";
        }
    }
    return 0;
}