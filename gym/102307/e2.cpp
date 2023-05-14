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
const int N = 2e5+5;
 

int n, d, al, w, a1, a2, w1, w2, r;
vector <pii> pts;
 
int st[4*N], v[N], lazy[4*N];
 
void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] += lazy[p];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
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
    if (l != r) st[p] = max(st[2*p], st[2*p+1]);
}
 
int main(){
	scanf("%d %d %d.%d", &n, &d, &a1, &a2);
    al = 100*a1 + a2;
    for(int i=0;i<n;i++){
		scanf("%d %d.%d", &r, &w1, &w2);
        w = 100*w1 + w2;
        pts.pb({w,r});
    }
    sort(pts.begin(),pts.end());
    vector <piii> eve;
    for(int i=0;i<n;i++) {
        eve.pb({pts[i].st,{-1,i}});
        if(pts[i].st + al >= 36000){
            eve.pb({0,{-1,i}});
            eve.pb({(pts[i].st + al) % 36000,{1,i}});
        }
        else eve.pb({pts[i].st + al,{1,i}});
    }
    sort(eve.begin(),eve.end());
    int ans = 0;
    for(int i=0;i<eve.size();i++){
        if(eve[i].nd.st == -1){
            update(1,1,N,pts[eve[i].nd.nd].nd,pts[eve[i].nd.nd].nd + d,1);
            ans = max(ans,st[1]);
        }
        if(eve[i].nd.st == 1){
            update(1,1,N,pts[eve[i].nd.nd].nd,pts[eve[i].nd.nd].nd + d,-1);
        }
    }
    printf("%d\n",ans);
    return 0;
}