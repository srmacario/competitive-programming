#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

map<string, int> id;
vector<vector<int>> adj;
vector<int> cnt[2];
int id_cnt = 0;

int dfs_mark(int u){
    if(adj[u].size() == 0){
        return cnt[1][u];
    }
    int bad = 0;
    for(int i = 0; i < adj[u].size(); i++){
        bad += dfs_mark(adj[u][i]);
    }
    cnt[1][u] = (bad == adj[u].size());
    return cnt[1][u];
}

int dfs(int u){
    int ans = 0;
    if(cnt[1][u]) return 1;
    for(int i = 0; i < adj[u].size(); i++){
        if(cnt[1][adj[u][i]]) ans += 1;
        else ans += dfs(adj[u][i]);
    }
    return ans;
}

void add_string(int par, string cur){
    id[cur] = ++id_cnt;
    adj.push_back({});
    cnt[0].push_back(0);
    cnt[1].push_back(0);
    adj[par].push_back(id[cur]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        id_cnt = 0;
        id.clear();
        adj.clear();
        cnt[0].clear();
        cnt[1].clear();
        adj.push_back({}), cnt[0].push_back(0), cnt[1].push_back(0);
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            string cur;
            int par = 0;
            for(char ch : s){
                cur += ch;
                if(ch == '/'){
                    if(!id.count(cur)) add_string(par, cur);
                    par = id[cur];
                }
            }
            if(!id.count(cur)) add_string(par, cur);
            cnt[1][id[cur]]++;
        }
        for(int i = 0; i < m; i++){
            string s;
            cin >> s;
            string cur;
            int par = 0;
            for(char ch : s){
                cur += ch;
                if(ch == '/'){
                    if(!id.count(cur)) add_string(par, cur);
                    par = id[cur];
                }
            }
            if(!id.count(cur)) add_string(par, cur);
            cnt[0][id[cur]]++;
        }
        int ans = 0;
        for(int i = 0; i < adj[0].size(); i++){
            dfs_mark(adj[0][i]);
        }
        for(int i = 0; i < adj[0].size(); i++){
            ans += dfs(adj[0][i]);
        }
        cout << ans << "\n";
    }
    return 0;
}