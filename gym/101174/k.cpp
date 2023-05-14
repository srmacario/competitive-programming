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
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int k;
int n, ordn, cnt;
map<piii, int> vis_3d, cmp_3d;
map<piii, piii> par_3d;
piii ord_3d[N];

map<pii, int> vis_2d, cmp_2d;
map<pii, pii> par_2d;
pii ord_2d[N];

pair<piii, piii> pts[N];
map<piii, vector<piii>> adj_3d;
map<pii, vector<pii>> adj_2d;

//3d kosaraju
void dfs_3d(piii u){
    vis_3d[u] = 1;
    for(auto v : adj_3d[u]) if(!vis_3d[v]) par_3d[v] = u, dfs_3d(v);
    ord_3d[ordn++] = u;
}

void dfst_3d(piii u){
    cmp_3d[u] = cnt, vis_3d[u] = 0;
    for(auto v : adj_3d[u]) if(vis_3d[v] and u != par_3d[v]) dfst_3d(v);
}

//2d kosaraju
void dfs_2d(pii u){
    vis_2d[u] = 1;
    for(auto v : adj_2d[u]) if(!vis_2d[v]) par_2d[v] = u, dfs_2d(v);
    ord_2d[ordn++] = u;
}

void dfst_2d(pii u){
    cmp_2d[u] = cnt, vis_2d[u] = 0;
    for(auto v : adj_2d[u]) if(vis_2d[v] and u != par_2d[v]) dfst_2d(v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> pts[i].st.st.st >> pts[i].st.st.nd >> pts[i].st.nd;
        cin >> pts[i].nd.st.st >> pts[i].nd.st.nd >> pts[i].nd.nd;
        
        adj_3d[pts[i].st].push_back(pts[i].nd);
        adj_3d[pts[i].nd].push_back(pts[i].st);

        adj_2d[pts[i].st.st].push_back(pts[i].nd.st);
        adj_2d[pts[i].nd.st].push_back(pts[i].st.st);
    }
    //kosaraju for 3d
    int n = adj_3d.size();
    for(auto i : adj_3d){
        if(!vis_3d[i.st]) dfs_3d(i.st);
    }
    for(int i = ordn - 1; i >= 0; --i){
        if(vis_3d[ord_3d[i]]) cnt++, dfst_3d(ord_3d[i]);
    }
    // db(n _ cnt);
    if(n == cnt) cout << "No true closed chains\n";
    else cout << "True closed chains\n";

    //kosaraju for 2d
    n = ordn = cnt = 0;
    n = adj_2d.size();
    for(auto i : adj_2d){
        if(!vis_2d[i.st]) dfs_2d(i.st);
    }
    for(int i = ordn - 1; i >= 0; --i){
        if(vis_2d[ord_2d[i]]) cnt++, dfst_2d(ord_2d[i]);
    }
    // db(n _ cnt);
    if(n == cnt) cout << "No floor closed chains\n";
    else cout << "Floor closed chains\n";
    return 0;
}