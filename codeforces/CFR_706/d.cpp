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

int a[N], l[N], r[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int mxl = 0, cntl = 0, mxr = 0 , cntr = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] > a[i-1]) l[i] = l[i-1] + 1;
        if(mxl == l[i]) cntl++;
        if(mxl < l[i]) mxl = l[i], cntl = 1;
    }
    for(int i = n-1; i >= 1; i--){
        if(a[i] > a[i+1]) r[i] = r[i+1] + 1;
        if(mxr == r[i]) cntr++;
        if(mxr < r[i]) mxr = r[i], cntr = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(l[i] == 0 or r[i] == 0) continue;
        if(!(l[i]%2) and !(r[i]%2) and l[i] == r[i]){
            if(max(l[i], r[i]) < max(mxl, mxr)) continue;
            if(mxl == l[i]) cntl--;
            if(mxr == r[i]) cntr--;
            if(cntl + cntr == 0) ans++;
            if(mxl == l[i]) cntl++;
            if(mxr == r[i]) cntr++;
        }
    }
    printf("%d\n", ans);
    return 0;
}