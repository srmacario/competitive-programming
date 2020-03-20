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
    const int N = 1e5+5;
     
    int n, m, vis[2*N], ord[2*N], ordn, cnt, cmp[2*N], val[N], z;
    vector <int> adj[2*N], adjt[2*N], chn;
     
    // Maps every "true" state of it to 2*i and every "false" one (i.e. ~i) to 2*i+1.
    int v (int x) { return 2*x; }
    int nv (int x) { return 2*x+1; }
     
    void add(int p, int q){
      adj[p^1].push_back(q);
      adj[q^1].push_back(p);
      adjt[q].push_back(p^1);
      adjt[p].push_back(q^1);
    }
     
    void dfs (int x) {
        vis[x] = 1;
        for (auto v : adj[x]) if (!vis[v]) dfs(v);
        ord[ordn++] = x;
    }
     
    void dfst (int x) {
        cmp[x] = cnt, vis[x] = 0;
        for(auto v : adjt[x]) if (vis[v]) dfst(v);
    }
     
    bool run2sat() {
        for (int i = 1; i <= n; i++) {
            if (!vis[v(i)]) dfs(v(i));
            if (!vis[nv(i)]) dfs(nv(i));
        }
        for (int i = ordn-1; i >= 0; i--)
            if (vis[ord[i]]) cnt++, dfst(ord[i]);
        for (int i = 1; i <= n; i++) {
            if (cmp[v(i)] == cmp[nv(i)]) return false;
            val[i] = cmp[v(i)] > cmp[nv(i)];
        }
        return true;
    }

    bool trun2sat() {
        chn.clear();
        for (int i = 1; i <= n; i++) {
            if (!vis[v(i)]) dfs(v(i));
            if (!vis[nv(i)]) dfs(nv(i));
        }
        for (int i = ordn-1; i >= 0; i--)
            if (vis[ord[i]]) cnt++, dfst(ord[i]);
        for (int i = 1; i <= n; i++) {
            if (cmp[v(i)] == cmp[nv(i)]) return false;
            val[i] = cmp[v(i)] > cmp[nv(i)];
            if(!val[i]) chn.pb(i);
        }
        return true;
    }
     
    void print(){
        cout << run2sat() << "\n";
        for(int i = 1;i<=m;i++){
            cout << i << ": " << val[i] << "\n";
        }
    }
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> m >> n;
        for(int i=0;i<n;i++){
            int a,b,p,q;
            cin >> a >> b;
            if(a<0) p = nv(-a);
            else p = v(a);
            if(b<0) q = nv(-b);
            else q = v(b);
            add(p,q);
        }
        if(!trun2sat()){
            cout << "0\n";
            return 0;
        }
        int cnt = 0;
        while(chn.size()){
            cnt++;
            for(int j = chn.size()-1;j>=0;j--){
                int i = chn[j];
                if(!val[i]) {
                    add(v(i),v(i));
                    if(run2sat()) continue;
                    else{
                        cout << cnt << "\n";
                        return 0;
                    }
                }
            }
            trun2sat();
        }
        cout << "-1\n";
        return 0;
    }