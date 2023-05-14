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
const int N = 505, M = 3e5+5;

int n, k, grid[N][N], vis[N][N], id[N][N], cnt[M], cntin[M], t_cnt[M], ans, cmp, t;

void dfs(int i, int j){
    id[i][j] = cmp;
    cnt[cmp]++;
    vis[i][j] = 0;
    if(vis[i-1][j] and grid[i-1][j]) dfs(i-1,j);
    if(vis[i+1][j] and grid[i+1][j]) dfs(i+1,j);
    if(vis[i][j-1] and grid[i][j-1]) dfs(i,j-1);
    if(vis[i][j+1] and grid[i][j+1]) dfs(i,j+1);
}

void init(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            cntin[id[i][j]]++;
        }
    }
}

void add_col(int i, int j, int v){
    for(int l=i;l<=i+k-1;l++){
        cntin[id[l][j]] += v;
    }
}

void add_row(int i, int j, int v){
    for(int l=j;l<=j+k-1;l++){
        cntin[id[i][l]] += v;
    }
}

void count(int i, int j){
    int cur = k*k;
    t++;
    for(int l=j;l<=j+k-1;l++){
        if(grid[i-1][l] and t_cnt[id[i-1][l]] < t){
            cur += cnt[id[i-1][l]] - cntin[id[i-1][l]];
            t_cnt[id[i-1][l]] = t;
        }
        if(grid[i+k][l] and t_cnt[id[i+k][l]] < t){
            cur += cnt[id[i+k][l]] - cntin[id[i+k][l]];
            t_cnt[id[i+k][l]] = t;
        }
    }
    for(int l=i;l<=i+k-1;l++){
        if(grid[l][j-1] and t_cnt[id[l][j-1]] < t){
            cur += cnt[id[l][j-1]] - cntin[id[l][j-1]];
            t_cnt[id[l][j-1]] = t;
        }
        if(grid[l][j+k] and t_cnt[id[l][j+k]] < t){
            cur += cnt[id[l][j+k]] - cntin[id[l][j+k]];
            t_cnt[id[l][j+k]] = t;
        }
    }
    ans = max(cur,ans);
}

void slide_right(int i){
    for(int j=2;j<=n-k+1;j++){
        add_col(i,j-1,-1);
        add_col(i,j+k-1,1);
        count(i,j);
    }
}

void slide_left(int i){
    for(int j=n-1;j>=k;j--){
        add_col(i,j+1,-1);
        add_col(i,j-k+1,1);
        count(i,j-k+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            grid[i+1][j+1] = (s[j] == '.');
            vis[i+1][j+1] = (s[j] == '.');
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]){
                ++cmp;
                dfs(i, j);
            }
        }
    }
    init();
    for(int i=1;i<=n-k+1;i++){
        if(i%2){
            count(i,1);
            slide_right(i);
            add_row(i,n-k+1,-1);
            add_row(i+k,n-k+1,1);
        }
        else{
            count(i,n-k+1);
            slide_left(i);
            add_row(i,1,-1);
            add_row(i+k,1,1);
        }
    }
    cout << ans << "\n";
    return 0;
}