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
const int N = 3605;

vi adj[N], button;
int dist[N], n, t;
pii mic = {INF,INF};

void bfs(int s){
    memset(dist,63,sizeof(dist));
    queue<int> q;
    dist[s] = 0;
    if(t == 0){
        mic.st = 0;
        mic.nd = 0;
    }
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto b : button){
            int nxt = u + b;
            if(nxt < 0) nxt = 0;
            if(nxt > 3600) nxt = 3600;
            if(dist[nxt] > dist[u] + 1){
                dist[nxt] = dist[u] + 1;
                if(nxt >= t){
                    if(nxt < mic.st){
                        mic.st = nxt;
                        mic.nd = dist[nxt];
                    }
                    else if(nxt == mic.st){
                        mic.nd = min(dist[nxt],mic.nd);
                    }
                }
                q.push(nxt);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        for(int i=0;i<N;i++) adj[i].clear();
        memset(dist,0,sizeof(dist));
        mic = {INF,INF};
        button.clear();
        cin >> n >> t;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            button.pb(x);
        }
        sort(button.begin(),button.end());
        bfs(0);
        cout << mic.nd << " " << mic.st - t << "\n";
    }
    return 0;
}