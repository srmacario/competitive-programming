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
const int K = 26;
const int N = 1e5+5, M = 1e6+6;

int idc(char c){
    if(c < 'a') return c - 'A' + 26;
    else return c - 'a';
}

int st[4*M], lazy[4*M];
int to[N], n, k;
bool has[N];

// ll bit[M];

// void add (int p, ll v) {
//     for (p+=2; p<N; p += p&-p) bit[p] += v;
// }

// ll query (int p) {
//     ll r = 0;
//     for (p+=2; p; p -= p&-p) r += bit[p];
//     return r;
// }

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] += (r-l+1)*lazy[p];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] += k;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    st[p] = st[2*p] + st[2*p+1];
}

struct Aho{

    struct Vertex{
        int next[K];
        int p = -1;
        char pch;
        int link = -1;
        int l, r, id = -1;
        int sum = 0;
        vi adj;
        Vertex(int par = -1, char ch = '$') : p(par), pch(ch) {
            fill(begin(next), end(next), -1);
        }
    };  
    int cnt = 0;
    vector<Vertex> t;

    Aho() : t(1){
    }

    void add_string(const string& s, int id){
        int v = 0;
        for (char ch : s){
            int c = idc(ch);
            if(t[v].next[c] == -1){
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        to[id] = v;
        has[id] = 1;
        t[v].sum = 1;
    }
    
    int get_link(int v){
        if(t[v].link == -1){
            if(v == 0 || t[v].p == 0) t[v].link = 0;
            else t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }

    int go(int v, char ch){
        int c = idc(ch);
        if(t[v].next[c] == -1){
            t[v].next[c] = (v == 0) ? 0 : go(get_link(v), ch);
        }
        return t[v].next[c];
    }
    
    void dfs(int i, int now){
        t[i].id = ++cnt;
        t[i].l = t[i].id;
        update(1,1,t.size(),t[i].l,t[i].l,t[i].sum + now);
        // add(t[i].l, t[i].sum + now), add(t[i].l + 1, -(t[i].sum + now));
        for(auto u : t[i].adj) if(t[u].id == -1) dfs(u, t[i].sum + now);
        t[i].r = cnt;
    }

    void gen_links(){
        for(int i = 0; i < t.size(); i++) t[i].link = get_link(i), t[t[i].link].adj.pb(i);
        dfs(0, 0);
    }

    int run(const string& s){
        ll ans = 0;
        int v = 0;
        for (char ch : s){
            int c = idc(ch);
            ans += query(1,1,t.size(),t[v].l,t[v].l);
            v = go(v, ch);
        }
        ans += query(1,1,t.size(),t[v].l,t[v].l);
        return ans;
    }

    void ins(int pos){
        if(!has[pos]) update(1,1,t.size(),t[to[pos]].l,t[to[pos]].r, 1), has[pos] = 1;
    }

    void rem(int pos){
        if(has[pos]) update(1,1,t.size(),t[to[pos]].l,t[to[pos]].r, -1), has[pos] = 0;
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cin >> n >> k;
    Aho aho;
    for(int i=1;i<=k;i++){
        string x;
        cin >> x;
        aho.add_string(x,i);
    }
    aho.gen_links();
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        if(c == '-'){
            int op;
            cin >> op;
            aho.rem(op);
        }
        if(c == '+'){
            int op;
            cin >> op;
            aho.ins(op);
        }
        if(c == '?'){
            string s;
            cin >> s;
            cout << aho.run(s) << "\n";
        }
    }
    return 0;
}