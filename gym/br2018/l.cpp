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

int q,n,k;
piii que[N];
int ans[N];

int bit[N];

void add (int p, int v){
    for(p += 2; p < N; p+= p&-p) bit[p] += v;
}

int query (int p){
    int r = 0;
    for (p += 2; p; p-= p&-p) r += bit[p];
    return r;
}

int rangesum(int a, int b){
    return query(b) - (a ? query(a-1) : 0);
}

void fact(int x){
    int p = 1;
    for(int i = 2; i*i <= x; i++){
        while(!(x%i)) {
            x /= i;
            p = i;
        }
        if(x == 1) break;
    }
    if(x != 1) p = x;
    add(p,1);
}

int main(){
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d%d",&que[i].st,&que[i].nd.st);
        que[i].nd.nd = i;
    }
    sort(que,que+q);
    int cur = 2;
    for(int i = 0; i < q; i++){
        for(; cur <= que[i].st; cur++) fact(cur);
        ans[que[i].nd.nd] = rangesum(1,que[i].nd.st);
    }
    for(int i = 0; i < q; i++) cout << ans[i] << "\n";
    return 0;
}