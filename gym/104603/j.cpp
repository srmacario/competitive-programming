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

int n, m, k;
vector<int> adj[N];
vector<int> forb;
vector<pii> edges;

bool check(int mid){
    set<int> cant;
    for(int i = 0; i <= mid; i++) cant.insert(forb[i]);
    for(auto e : edges){
        if(!cant.count(e.st) and !cant.count(e.nd)){
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    forb.resize(k + 1);
    for(int i = 0; i <= k; k++) cin >> forb[k];
    int l = 0, r = k;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    return 0;
}