#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 5005;

int A, B, E, P, alc[N], cnt, aux, par[N];
vi adj[N];

void dfs(int s){
    par[s]++;
    cnt++;
    alc[s] = aux;
    for(auto u: adj[s]){
        if(alc[u] != aux) dfs(u)/*, db(u)*/;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B >> E >> P;
    for(int i=0;i<P;i++){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    int respA = 0, respB = 0, never = 0;
    for(int i=0;i<E;i++){
        aux++;
        cnt = 0;
        dfs(i);
        if(E - cnt < A) respA++;
        if(E - cnt < B) respB++;
        par[i]--;
    }
    for(int i=0;i<E;i++) if(par[i] >= B) never++;
    cout << respA << "\n" << respB << "\n" << never << "\n";
    return 0;
}