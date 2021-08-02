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
const int N = 2e5+5;

int k, n, m, t[N], tans[N];
pair<pii, vii> grid[N];
vii ans;

void print(){
    cout << "\n";
    for(int i = 0; i < k; i++){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                cout << grid[i].nd[x][y];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n >> m;
    ans.resize(n);
    for(int j = 0; j < n; j++) ans[j].resize(m);
    for(int i = 0; i < k; i++){
        grid[i].nd.resize(n);
        for(int j = 0; j < n; j++) grid[i].nd[j].resize(m);
    }
    for(int i = 0; i < k; i++){
        int cnt = 0;
        for(int x = 0; x < n; x++){
            string s;
            cin >> s;
            for(int y = 0; y < m; y++){
                (grid[i].nd)[x][y] = s[y] - '0';
                cnt += grid[i].nd[x][y];
            }
        }
        grid[i].st.st = n*m - cnt;
        grid[i].st.nd = i;
    }
    sort(grid, grid + k);
    
    // print();
    for(int i = 0; i < k; i++) t[i] = i + 2;
    for(int i = 0; i < k; i++){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(i){
                    if(grid[i].nd[x][y] > grid[i-1].nd[x][y]){
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                    else if(grid[i].nd[x][y] < grid[i - 1].nd[x][y]){
                        ans[x][y] = t[i-1];
                    }  
                }
                else{
                    if(!grid[i].nd[x][y]) ans[x][y] = 1;
                }
            }
        }
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(!ans[x][y]) ans[x][y] = t[k-1];
        }
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << ans[x][y] << " ";
        }
        cout << "\n";
    }
    
    for(int i = 0; i < k; i++) tans[grid[i].st.nd] = t[i];
    for(int i = 0; i < k; i++) cout << tans[i] << " ";
    cout << "\n";
    return 0;
}