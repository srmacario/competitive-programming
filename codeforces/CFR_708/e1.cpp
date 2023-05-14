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
const int N = 1e7+10;

int cmp[N];
vi pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}
set <int> cur;

int fact(int n){
    int cur = 1;
    for(int i = 0; pr[i]*pr[i] <= n; i++){
        int cnt = 0;
        while(n % pr[i] == 0){
            cnt++;
            n/=pr[i];
        }
        if(cnt&1) cur *= pr[i];
    }
    if(n > 1) cur *= n;
    return cur;
}

int main(){
    primes();
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k, cnt = 1;
        cur.clear();
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            x = fact(x);
            if(cur.count(x)){
                cur.clear();
                cnt++;
            }
            cur.insert(x);
        }
        printf("%d\n", cnt);
    }
    return 0;
}