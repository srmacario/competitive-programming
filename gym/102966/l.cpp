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
const int N = 1e7+5;

int cmp[N];
vi pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

int factorize(int n, int m) {
    set<int> ans;
    for(int i = 0; pr[i]*pr[i] <= n; i++){
        if(n % pr[i] == 0) ans.insert(pr[i]);
        while (n % pr[i] == 0) n /= pr[i];
    }
    for(int i = 0; pr[i]*pr[i] <= m; i++){
        if(m % pr[i] == 0) ans.insert(pr[i]);
        while (m % pr[i] == 0) m /= pr[i];
    }
    if (n > 1) ans.insert(n);
    if (m > 1) ans.insert(m);
    return (int) ans.size();
}

int main(){
    primes();
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        printf("%d\n", factorize(a, b));
    }
    return 0;
}