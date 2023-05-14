#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, p[N][N], par[N];
vector<pair<int, pii>> edge;

int find(int a){
    return (a == par[a] ? a : par[a] = find(par[a]));
}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(a > b) swap(a, b);
    par[b] = a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        par[i] = i;
        for(int j = 1; j <= n; j++){
            cin >> p[i][j];
            edge.push_back({-p[i][j], {i, j}});
        }
    }
    sort(edge.begin(), edge.end());
    ll cost = 0;
    vector<pii> ans;
    for(auto e : edge){
        int a = find(e.nd.st), b = find(e.nd.nd);
        if(a > b) swap(a, b);
        if(a != b){
            unite(e.nd.st, e.nd.nd);
            ans.push_back({a, b});
            cost -= e.st;
        }
    }
    cout << cost << "\n";
    for(auto a : ans) cout << a.st << " " << a.nd << "\n";
    return 0;
}