#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

vector <pii> adj[N];
ll vis[N], dist[N];

struct Node{
    Node *ch[2];
    Node(){
        ch[0] = ch[1] = nullptr;
    }
};

void dfs(int s){
    vis[s] = 1;
    for(auto u : adj[s]) if(!vis[u.st]){
        dist[u.st] = dist[s]^u.nd;
        dfs(u.st);
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t,n;
    while(cin >> n){
        cl(adj,0); cl(vis,0); cl(dist,0);
        Node *root = new Node();
        for(int i=0;i<n-1;i++){
            int a,b,c;
            cin >> a >> b >> c;
            adj[a].pb({b,c});
            adj[b].pb({a,c});
        }
        dfs(1);
        for(int i=1;i<=n;i++){
            Node *cur = root;
            for(ll j = 31;j>=0;j--){
                ll b = (dist[i] & (1ll << j))>0;
                if(!(cur->ch[b])){
                    cur->ch[b] = new Node();
                }
                cur = cur->ch[b];
            }
        }
        for(int i=1;i<=n;i++){
            Node *cur = root;
            ll ans = 0;
            for(int j = 31;j>=0;j--){
                int b = (dist[i]&(1ll << j))>0;
                if(cur->ch[!b]){
                    ans += (1ll << j);
                    cur = cur->ch[!b];
                }
                else{
                    if(!cur->ch[b]) cur->ch[b] = new Node();
                    cur = cur->ch[b];
                }
            }
            cout << ans << "\n";
        }
        delete root;
    }
    return 0;
}