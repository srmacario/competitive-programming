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
const int N = 105;

int a[N];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, u, v;
        scanf("%d%d%d", &n, &u, &v);
        bool ok = false;
        set <int> cnt;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            cnt.insert(a[i]);
            if(i and abs(a[i] - a[i-1]) > 1) ok = true;
        }
        if(cnt.size() == 1) printf("%d\n", min({u+v, v+v}));
        else if (!ok) printf("%d\n", min(u,v));
        else printf("0\n");
    }
    return 0;
}