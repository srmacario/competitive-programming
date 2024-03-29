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

int par[N], n, m, sz[N], inc[N], his[N];
vi sum[N];

int find(int a){
    while(par[a] != a){
        a = par[a];
    }
    return a;
}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    his[b] = inc[a];
    sz[a] += sz[b];
}

int get_sum(int a){
    int s = 0;
    s += sum[a][sum[a].size()-1] - sum[a][0];
    while(par[a] != a){
        s += sum[par[a]][sum[par[a]].size()-1] - sum[par[a]][his[a]];
        a = par[a];
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        par[i] = i;
        sz[i] = 1;
        sum[i].pb(0);
    }
    for(int i = 0; i < m; i++){
        string op;
        int x, y;
        cin >> op;
        if(op == "get"){
            cin >> x;
            cout << get_sum(x) << "\n";
        }
        else{
            cin >> x >> y; 
            if(op == "add"){
                int p = find(x);
                sum[p].pb(y + sum[p].back());
                inc[p]++;
            }
            else{
                unite(x,y);
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(auto x : sum[i]) cout << x << " ";
    //     db(his[i] _ inc[i]);
    //     cout << "\n";
    // }
    return 0;
}