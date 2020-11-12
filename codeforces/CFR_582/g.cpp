#include <bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define pb push_back
#define pii pair <int, int>
#define triplet pair <int,pii>
#define vi vector<int>
#define vii vector<vi>
#define clr(x) x.clear()
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 200005;

using namespace std;

int par[N], sz[N];
ll ans[N];
vector<triplet> edges;

ll choose(ll n){
    return (n*(n-1))/2;
}

int find(int a){ return par[a] == a ? a : par[a] = find(par[a]);}

void unite(int a, int b, int i){
    if ((a = find(a)) == (b = find(b))) return;
    ans[i] -= choose(sz[a]);
    ans[i] -= choose(sz[b]);
    if (sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    ans[i] += choose(sz[a]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    // ENTRADA
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.pb({w,{u,v}});
    }
    //INICIALIZANDO OS PARENTES E O TAMANHO DO PARENTE PRO DSU
    for(int i=1;i<=n;i++) par[i] = i, sz[i] = 1;
    //ORDENANDO O VETOR DE ARESTAS
    sort(edges.begin(),edges.end());
    int count = 0;
    if(n>1){ // SÓ PRA N BUGAR CASO N = 1
        for(int i=1;i<=200000;i++){ //ITERANDO ENTRE OS TAMANHOS DE ARESTAS
            while(count!=n){//ITERANDO SOBRE AS ARESTAS QUE SÃO MENORES QUE O TAMANHO DADO
                if(edges[count].st <= i) unite(edges[count].nd.st,edges[count].nd.nd,i), count++;
                else break;
            }
            ans[i+1] = ans[i]; //CARREGA A RESPOSTA PARA O PRÓXIMO TAMANHO DE ARESTA A SER VERIFICADO
        }
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        cout << ans[x] << " ";
    }
    cout << "\n";
    return 0;
}