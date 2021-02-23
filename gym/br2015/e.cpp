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
const int N = 1e5+5;

int n,m;
int E[N];
int st[4*N], lazy[4*N];
vector<piii>store;

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] = lazy[p];
        if (l != r) {
            lazy[2*p] = lazy[p];
            lazy[2*p+1] = lazy[p];
        }
        lazy[p] = 0;
    }
}

int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return min(x, y);
}

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = k;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    if (l != r) st[p] = min(st[2*p], st[2*p+1]);
}

int busca(int pos, int targ){
    int l = pos-1, r = n;
    while(l < r){
        int mid = (l+r+1)/2;
        if(E[mid] - E[pos-1] > targ) r = mid-1;
        else l = mid;
    }
    return l;
}

int main(){
    //for(int i=0;i<4*N;i++) st[i] = {INF,INF};
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&E[i]);
        E[i] += E[i-1];
        cout << E[i] << " ";
    }
    cout << "\n";
    for(int i=1;i<=m;i++){
        int l,s,c;
        scanf("%d%d%d",&l,&s,&c);
        store.pb({l,{s,c}});
    }
    sort(store.begin(),store.end());
    for(int i=0;i<m; i++){
        piii s = store[i];
        int r = busca(s.st,s.nd.st);
        if(r >= s.st){
            update(1,1,n,s.st,r,s.nd.nd);
            db(query(1,1,n,s.st,s.st));
        }
        cout << s.st << " " << r << "\n";
    }/*
    int ans = 0,last = 0;
    for(int i=0;i<m;i++){
        piii s = store[i];
        pii cur = query(1,1,n,s.st,s.st);
        db(cur.st _ -cur.nd);
        if(cur.st == INF or -cur.nd < last){
            printf("-1\n");
            return 0;
        }
        if(-cur.nd != last) ans += cur.st;
        last = -cur.nd;
    }*/
   // printf("%d\n",ans);
    return 0;
}