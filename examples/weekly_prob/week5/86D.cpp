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
const int N = 1e6+5, sz = 1e3;

int cur_l = 1, cur_r = 0;
ll sqr, a[N], cnt[N];
//(k+1)^2 = k^2 + 2k + 1
//(k-1)^2 = k^2 - 2*k + 1;

struct Query {
    int l, r, idx;
    Query(int i, int j, int id) : l(i), r(j), idx(id){}
    bool operator <(Query o) const{
        pii p = {l/sz, r}, q = {o.l/sz, o.r};
        if(p.st != q.st) return p < q;
        return (p.st & 1) ? (p.nd < q.nd) : (p.second  > q.second); 
        // return make_pair(l/sz, r) < make_pair((o.l/sz), o.r);
    }
};

bool cmp(Query a, Query b){
    return a.idx < b.idx;
}

void rem(int idx){
    sqr = sqr + (1 - 2*cnt[a[idx]])*a[idx];
    cnt[a[idx]]--;
    //db(0 _ sqr);
}
void add(int idx){
    sqr = sqr + (1 + 2*cnt[a[idx]])*a[idx];
    cnt[a[idx]]++;
    //db(1 _ sqr);
}

vector<ll> mo( vector<Query> queries){
    vector<ll> ans(queries.size());
    sort(queries.begin(), queries.end());
    for(Query q : queries){
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            rem(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            rem(cur_r);
            cur_r--;
        }
        ans[q.idx] = sqr;
    }
    return ans;
}

int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        //sqr = sqr + (2*cnt[a[i]] + 1)*a[i];
        //db(sqr);
        //cnt[a[i]]++;
    }
    vector<Query> q;
    for(int i = 0; i < t; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        q.pb(Query(l,r,i));
    }
    vector<ll> resp = mo(q);
    for(ll r : resp){
        printf("%lld\n", r);
    }
    return 0;
}