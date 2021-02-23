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
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

pii pl[N], ver[N];
map <int,int> id;

int st[4*N], v[N], lazy[4*N];

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] = (r-l+1)-st[p];
        if (l != r) {
            lazy[2*p] ^= 1,       lazy[2*p+1] ^= 1;
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

void update (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = 1;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j);
    update(2*p+1, (l+r)/2+1, r, i, j);
    if (l != r) st[p] = st[2*p] + st[2*p+1];
}

int main(){
    int p,v;
    scanf("%d%d",&p,&v);
    set<int> conj;
    vi nums;
    for(int i=1;i<=p;i++){
        scanf("%d %d",&pl[i].st, &pl[i].nd);
        nums.pb(pl[i].st), nums.pb(pl[i].nd);
    }
    for(int i=1;i<=v;i++){
        scanf("%d %d",&ver[i].st, &ver[i].nd);
        nums.pb(ver[i].st), nums.pb(ver[i].nd);
    }
    //COMPRESS
    sort(nums.begin(),nums.end());
    int cnt = 1;
    for(int i=0;i<nums.size();i++){
        if(!i) id[nums[i]] = cnt;
        else{
            if(id[nums[i]] == id[nums[i-1]]) id[nums[i]] = cnt;
            else id[nums[i]] = ++cnt;
        }
    }
    int n = cnt+5;
    vector <pair<pii,pii>> eve;
    for(int i=1;i<=p;i++){
        eve.pb({pl[i],{INF,i}});
    }
    int ini;
    if(ver[1].st == ver[2].st) ini = 1;
    else ini = 2;
    for(int i=ini;i<=v;i+=2){
        int j = i+1;
        if(j > v) j = 1;
        eve.pb({ver[i],ver[j]});
    }
    sort(eve.begin(),eve.end());
    ll ans = 0;
    for(int i=0;i<eve.size();i++){
        //cout << eve[i].st.st << " " << eve[i].st.nd << " " << eve[i].nd.st << " " << eve[i].nd.nd << "\n";
        if(eve[i].nd.st == INF){
            if(!query(1,1,n,id[eve[i].st.nd],id[eve[i].st.nd])) ans += eve[i].nd.nd;
        }
        else{
            int l = min(id[eve[i].st.nd],id[eve[i].nd.nd]);
            int r = max(id[eve[i].st.nd],id[eve[i].nd.nd]);
            update(1,1,n,l+1,r);
            //db(query(1,1,n,id[eve[i].st.nd],id[eve[i].st.nd]));
        }
    }
    printf("%lld\n",ans);
    return 0;
}