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
const int N = 3e5+5;


int n, adj[N], l[2][N], r[2][N];
string s;

int dfsr(int u, int id){
    if(~r[id][u]) return r[id][u];
    r[id][u] = 1;
    if(u == n) return r[id][u];
    if(id){
        if(!adj[u]) r[id][u] += dfsr(u+1, id^1);
    }
    else{
        if(adj[u]) r[id][u] += dfsr(u+1, id^1);
    }
    return r[id][u];
}

int dfsl(int u, int id){
    if(~l[id][u]) return l[id][u];
    l[id][u] = 1;
    if(u == 0) return l[id][u];
    if(id){
        if(adj[u-1]) l[id][u] += dfsl(u-1, id^1);
    }
    else{
        if(!adj[u-1]) l[id][u] += dfsl(u-1, id^1);
    }
    return l[id][u];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i=0;i<2;i++){
            for(int j=0;j<=n;j++) r[i][j] = l[i][j] = -1;
        }
        for(int i=0;i<n;i++) adj[i] = (s[i] == 'R');
        for(int i=0;i<=n;i++){
            r[0][i] = dfsr(i,0);
        }
        for(int i=n;i>=0;i--){
            l[0][i] = dfsl(i,0);
        }
        for(int i=0;i<=n;i++) cout << r[0][i] + l[0][i] - 1 << " ";
        cout << "\n";
    }
    return 0;
}