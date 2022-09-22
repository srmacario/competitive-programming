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
const int N = 1e5+5, MX = 1e9;

int n;

#include <bits/stdc++.h>

/* tested:
    https://www.spoj.com/problems/BGSHOOT/
   ref:
    https://maratona.ic.unicamp.br/MaratonaVerao2022/slides/AulaSummer-SegmentTree-Aula2.pdf
*/
vector<int> e, d, lazy;
vector<ll> st;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    st.push_back(0);
    lazy.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return st.size() - 1;
}

void push(int pos, int ini, int fim){
    if(pos == 0) return;
    if (lazy[pos]) {
        st[pos] = (fim - ini + 1) - st[pos];
        // RMQ (max/min)   -> update: = lazy[p],         incr: += lazy[p]
        // RSQ (sum)       -> update: = (r-l+1)*lazy[p], incr: += (r-l+1)*lazy[p]
        // Count lights on -> flip:   = (r-l+1)-st[p];
        if (ini != fim) {
            if(e[pos] == 0){
                int aux = create();
                e[pos] = aux;
            }
            if(d[pos] == 0){
                int aux = create();
                d[pos] = aux;
            }
            lazy[e[pos]] ^= 1;
            lazy[d[pos]] ^= 1;
            // update:    lazy[2*p] = lazy[p],  lazy[2*p+1] = lazy[p];
            // increment: lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
            // flip:      lazy[2*p] ^= 1,       lazy[2*p+1] ^= 1;
        }
        lazy[pos] = 0;
    }
}

void update(int pos, int ini, int fim, int p, int q, int val){
    if(pos == 0) return;

    push(pos, ini, fim);

    if(q < ini || p > fim) return;

    if(p <= ini and fim <= q){
        lazy[pos] = 1;
        // update:    lazy[p] = k;
        // increment: lazy[p] += k;
        // flip:      lazy[p] = 1;
        push(pos, ini, fim);
        return;
    }

    int m = (ini + fim) >> 1;
    if(e[pos] == 0){
        int aux = create();
        e[pos] = aux;
    }
    update(e[pos], ini, m, p, q, val);
    if(d[pos] == 0){
        int aux = create();
        d[pos] = aux;
    }
    update(d[pos], m + 1, fim, p, q, val);
    st[pos] = st[e[pos]] + st[d[pos]];
}

ll query(int pos, int ini, int fim, int p, int q){
    if(pos == 0) return 0;

    push(pos, ini, fim);

    if(q < ini || p > fim) return 0;

    if(p <= ini and fim <= q) return st[pos];
    
    int m = (ini + fim) >> 1;
    return query(e[pos], ini, m, p, q) + query(d[pos], m + 1, fim, p, q);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<pair<pii, pii>> rect(n);
    //point, open/close, max y 
    vector<pair<pii,pii>> events;
    for(int i = 0; i < n; i++){
        cin >> rect[i].st.st >> rect[i].st.nd >> rect[i].nd.st >> rect[i].nd.nd;
        events.push_back({{min(rect[i].st.st, rect[i].nd.st), min(rect[i].st.nd, rect[i].nd.nd)}, {0, max(rect[i].st.nd, rect[i].nd.nd)}});
        events.push_back({{max(rect[i].st.st, rect[i].nd.st), min(rect[i].st.nd, rect[i].nd.nd)}, {1, max(rect[i].st.nd, rect[i].nd.nd)}});
    }
    sort(events.begin(), events.end());
    ll ans = 0, last_x = 0;
    create(), create();
    for(auto e : events){
        ans += 1ll * (e.st.st - last_x) * query(1, 0, MX, 0, MX);
        update(1, 0, MX, e.st.nd, e.nd.nd - 1, 1);
        last_x = e.st.st;
    }
    cout << ans << "\n";
    return 0;
}