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

int n, k;
int v[N];

int binS(int l, int r, int targ){
    while(l < r){
        int m = (l+r)/2;
        if(v[m] == targ) return m;
        else if(v[m] < targ) l = m + 1;
        else r = m - 1;
    }
    if(v[l] == targ) return l;
    return -1;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v, v + n);
    for(int i = 0; i < k; i++){
        int x;
        scanf("%d", &x);
        int pos = binS(0, n-1, x);
        if(pos == -1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}