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
const int N = 1e5+5;

int n, m, where[N], cnt[N];
queue<int> q;
set<int> group[2];
map<int, set<int>> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) group[0].insert(i);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        s[u].insert(v), s[v].insert(u);
        cnt[u]++, cnt[v]++;
        if(s[u].size() == 2) q.push(u);
        if(s[v].size() == 2) q.push(v);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(cnt[u] < 2) continue;
        group[where[u]].erase(u);
        where[u] ^= 1;
        group[where[u]].insert(u);
        for(auto enemy : s[u]){
            if (where[enemy] == where[u]){
                if(++cnt[enemy] == 2) q.push(enemy);
                cnt[u]++;
            }
            else{
                cnt[enemy]--;
                cnt[u]--;
            }
        }
    }
    if(group[0].size() and group[1].size()){
        cout << "2\n";
        for(int i = 0; i < 2; i++){
            for(auto u : group[i]){
                cout << u << " ";
            }
            cout << "\n";
        }
    }
    else{
        cout << "1\n";
        int i = 0;
        if(group[1].size()) i = 1;
        for(auto u : group[i]) cout << u << " ";
        cout << "\n";
    }
    return 0;
}