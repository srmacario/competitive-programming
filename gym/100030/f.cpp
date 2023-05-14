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
const int N = 6e4+5, M = 205;

string dic[N];
char dummy[50];
map<pair<string, int>, vi> node;
int par[N], distv[N], cnt, n;

void bfs(int s){
    cl(distv, 63);
    distv[1] = 0;
    par[1] = 1;
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int j = 0; j < dic[u].size(); j++){
            string w = dic[u];
            w.erase(w.begin() + j);
            for(auto v : node[{w,j}]){
                if(distv[v] > distv[u] + 1){
                    par[v] = u;
                    distv[v] = distv[u] + 1;
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf(" %s", dummy);
        dic[i] = dummy;
        for(int j = 0; j < dic[i].size(); j++){
            string w = dic[i];
            w.erase(w.begin() + j);
            node[{w, j}].pb(i);
        }
    }
    bfs(1);
    if(distv[n] == INF){
       printf("FAIL\n");
    }
    else{
        int cur = n;
        vector<string> ans;
        ans.pb(dic[n]);
        while(par[cur] != cur){
            ans.pb(dic[par[cur]]);
            cur = par[cur];
        }
        printf("%d\n", distv[n] + 1);
        for(int i = ans.size()-1; i >= 0; i--) printf("%s\n", ans[i].c_str());
    }
    return 0;
}