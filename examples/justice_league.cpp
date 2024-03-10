//https://www.beecrowd.com.br/judge/pt/problems/view/1417
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
const int N = 1e5+5, X = 3e2 + 5;

int h, r, is_hero[N], cnt[N];
vector<int> adj[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin >> h >> r;
        if(!h and !r) break;
        for(int i = 1; i <= h; i++) adj[i].clear();
        for(int i = 0; i < r; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = false;
        for(int x = 1; x < X; x++){
            bool tmp = true;
            int heroes = 0;
            for(int i = 1; i <= h; i++) cnt[i] = is_hero[i] = 0;
            for(int i = 1; i <= h; i++){
                if(adj[i].size() >= x) is_hero[i] = 1;
                else if(adj[i].size() == x - 1){
                    int heroes2 = 0;
                    for(auto v : adj[i]){
                        heroes2 += ((adj[v].size() == x - 1) or (is_hero[v]));
                    }
                    if(heroes2 == x - 1) is_hero[i] = 1;
                }
                if(is_hero[i]){
                    for(auto v : adj[i]) cnt[v]++;
                }
                heroes += is_hero[i];
            }
            for(int i = 1; i <= h; i++){
                if(is_hero[i] and (cnt[i] != x - 1)) tmp = false;
                if(!is_hero[i] and (cnt[i] != adj[i].size())) tmp = false;
            }
            if(tmp){
                ans = tmp;
                break;
            }
        }
        if(ans) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}