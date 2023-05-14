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

int x, marcB[N], matchB[N], matchA[N], ans, n, m, p, r[N], c[N];
vi adj[N];

bool dfs(int v){
    for(int i = 0; i < adj[v].size(); i++){
        int viz = adj[v][i];
        if(marcB[viz] == 1 ) continue;
        marcB[viz] = 1;

        if((matchB[viz] == -1) || dfs(matchB[viz])){
            matchB[viz] = v;
            matchA[v] = viz;
            return true;
        }
    
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n){
        ans = x = m = p = 0;
        vector<string> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        int cnt = 1, chn = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j] == 'X'){
                    if(chn) cnt++, chn = 0;
                }
                else r[i*n+j] = cnt, chn = 1;
            }
            if(chn) cnt++, chn = 0;
        }
        cnt=1, chn = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[j][i] == 'X'){
                    if(chn) cnt++, chn = 0;
                }
                else c[j*n+i] = cnt, chn = 1;
            }
            if(chn) cnt++, chn = 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m = max(m,r[i*n+j]);
                p = max(p,c[i*n+j]); 
                if(r[i*n+j]) adj[r[i*n+j]].pb(c[i*n+j]);
            }
        }
        for(int i = 0; i<=m; i++) matchA[i] = -1;
        for(int j = 0; j<=p; j++) matchB[j] = -1;
        bool aux = true;
        while(aux){
            for(int j=1; j<=p; j++) marcB[j] = 0;
            aux = false;
            for(int i=1; i<=m; i++){
                if(matchA[i] != -1) continue;
                if(dfs(i)){
                    ans++;
                    aux = true;
                }
            }
        }
        for (int i = 1; i <= m; i++) adj[i].clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                r[i*n+j] = c[i*n+j] = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}