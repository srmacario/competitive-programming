#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n;
ll a[N], b[N], sa, sb;

bool work(int k){
    int p = 0, f = 0;
    for(int i = 0; i < n; i++){
        int r = a[i];
        if(p < i - k){
            p = i - k;
            f = 0;
        }
        while(r){
            if(p > i + k || p >= n)
                return false;
            if(b[p] - f > r){
                f += r;
                r = 0;
            }
            else{
                r -= b[p] - f;
                f = 0;
                p++;
            }
        }
    }
    return true;
}

int bs(){
    int l = 0, r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(work(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        sa += a[i];
    }
    for(int i = 0; i < n; i++){
        scanf("%lld", &b[i]);
        sb += b[i];
    }
    if(sa > sb)
        printf("-1\n");
    else
        printf("%d\n", bs());
    return 0;
}