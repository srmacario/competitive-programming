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
const int N = 1e4+5;

int n[2],freq[2][N][50][50];
string lis[2][N];

void pre(){
    for(int l=0;l<2;l++){
        for(int k=0;k<n[l];k++){
            string s = lis[l][k];
            for(int i=0;i<s.size();i++){
                for(int j=0;j<26;j++){
                    if(s[i]-'a' == j) freq[l][k][i][j] = 1;
                    else freq[l][k][i][j] = 0;
                }
                if(i) for(int j=0;j<26;j++) freq[l][k][i][j] += freq[l][k][i-1][j];
            }
        }
    }    
}

int x, marcB[N], matchB[N], matchA[N], ans;
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
    while(cin >> n[0] >> n[1]){
        for(int k=0;k<2;k++){
            for(int i=0;i<n[k];i++){
                cin >> lis[k][i];
            }
        }
        pre();
        for(int i=0;i<n[1];i++){
            for(int j=0;j<n[0];j++){
                bool ok = true;
                for(int k=0;k<26;k++){
                    if(freq[1][i][lis[1][i].size()-1][k] > freq[0][j][lis[0][j].size()-1][k]){
                        ok = false;
                        break;
                    }
                }
                if(ok) adj[i].pb(j+n[1]);
            }
        }
        ans = 0;
        for(int i = 0; i<=n[0]+n[1]; i++) matchA[i] = -1;
        for(int j = 0; j<=n[0]+n[1]; j++) matchB[j] = -1;
        bool aux = true;
        while(aux){
            for(int j=0; j<n[0]+n[1]; j++) marcB[j] = 0;
            aux = false;
            for(int i=0; i<n[1]; i++){
                if(matchA[i] != -1) continue;
                if(dfs(i)){
                    ans++;
                    aux = true;
                }
            }
        }
        cout << ans << "\n";
        for(int i=0;i<=n[0]+n[1];i++) adj[i].clear();
    }
    return 0;
}