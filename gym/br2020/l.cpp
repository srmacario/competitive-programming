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

int s[N], d[N], pre[3*N], last;
pii ans = {INF, INF};

int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &s[i], &d[i]);
        pre[s[i]]++, pre[s[i] + d[i] + 1]--;
        last = max(s[i] + d[i], last);
    }
    for(int i = 1; i <= 2*last; i++){
        pre[i] += pre[i-1];
    }
    for(int i = 0; i <= 480; i++){
        int cur = 0;
        for(int j = i; j <= last; j += x){
            cur += pre[j];
        }
        ans = min(ans, {cur, i});
    }
    printf("%d %d\n", ans.nd, ans.st);
    return 0;
}