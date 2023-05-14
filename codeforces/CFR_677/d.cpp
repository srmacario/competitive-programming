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
const int N = 5005;

vi adj[N];
map <int,int> gang;

void dfs(int node, int sz){
    if(sz < 0) return;
    if(adj[sz].size() == 1) return;
    int tmp = adj[sz].back();
    adj[sz].pop_back(), adj[sz][0]--;
    cout << node << " " << tmp << "\n";
    dfs(tmp,sz-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        gang.clear();
        int n, cnt = 0;
        cin >> n;
        for(int i = 0; i<N;i++){
            adj[i].clear();
            adj[i].pb(INF);
        }
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(!gang[x]) gang[x] = ++cnt;
            x = gang[x];
            if(adj[x].size() > 1) adj[x][0]++;
            else adj[x][0] = 1;
            adj[x].pb(i);
        }
        sort(adj, adj + N);
        int last = 0;
        for(int i = 0; i<N;i++){
            if(adj[i].size() > 1) last = i;
            else break;
        }
        if(last){
            cout << "YES\n";
            int root = adj[0].back();
            adj[0].pop_back();
            adj[0][0]--;
            for(int i=adj[last].size()-1;i>0;i--){
                cout << root << " " << adj[last][i] << "\n";
                dfs(adj[last][i], last - 1);
            }
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}