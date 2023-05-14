#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector <int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

map<string,int> num;
map<int,int> mark;
int n, vis[N], cnt, k, ans;
vi adj[N];
vector <string> names[N];

void add_vert(string y){
    string cmp = "PROGRAM", aux;
    int l = 0;
    for(int i=0; i < y.size();i++){
        if(y[i] == ':'){
            l++;
            continue;
        }
        if(l < 2) continue;
        aux += y[i];
    }
    if(aux == cmp) mark[num[y]] = 1;
}

void dfs(int u){
    ans++;
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]) dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1; i <= n; i++){
        string s;
        cin >> s;
        num[s] = i;
        add_vert(s);
        cin >> k;
        for(int j=0;j<k;j++){
            string x;
            cin >> x;
            names[i].pb(x);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0;j<names[i].size();j++){
            adj[num[names[i][j]]].pb(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(mark[i] and !vis[i]) dfs(i);
    }
    cout << n - ans << "\n";
    return 0;
}
