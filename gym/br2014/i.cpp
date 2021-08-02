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

int n, f, vis[N], friends[N], tot;
pii max_child[N];
vector<pii> adj[N];

int dfs(int s, int w){
    vis[s] = 1;
    int ans = 0;
    pii mx = {0,0};
    for(auto p : adj[s]){
        //propaga o dfs pros filhos
        if(!vis[p.nd]){
            //recebe a soma acumulada abaixo
            int down = dfs(p.nd, p.st);
            //guarda a soma acumulada do maior filho de s
            mx = max(mx, {down, p.nd});
            //incrementa a soma acumulada total para aquele nó
            ans = mx.st;
            // db(s _ p.nd _ ans);
        }
    }
    //se for um amigo (folha), ou já estiver algo acumulado incrementa o custo para subir aquela raiz
    if(friends[s] or ans) ans += w, tot += w;;
    //atribui ao filho máximo de s o mx
    max_child[s] = mx;
    // db(s _ ans _ mx.st _ mx.nd);
    // db(s _ ans _ max_child[s].st _ max_child[s].nd);
    return ans;
}

//desce a arvore procurando os ramos de maior custo para nao ter que subir novamente
void redfs(int s){
    if(!max_child[s].st) return;
    for(auto p : adj[s]){
        //se for o filho de maior custo, retira aquela aresta e desce
        if(p.nd == max_child[s].nd){
            tot -= p.st;
            redfs(p.nd);
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> f;
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
    }
    for(int i = 0; i < f; i++){
        int x;
        cin >> x;
        friends[x] = 1;
    }
    dfs(1, 0);
    redfs(1);
    cout << tot << "\n";
    return 0;
}