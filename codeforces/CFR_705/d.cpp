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
const int N = 2e5+10; // Upper limit to n

int cmp[N];
map <int,int> num[N];
multiset<int> cnt[N];

ll fexp(ll a, ll b, ll m = MOD) {
  ll r=1;
  for (a %= m; b; b>>=1, a=(a*a)%m) if (b&1) r=(r*a)%m;
  return r;
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        for(int j = 2; j*j <= x; j++){
            bool ok = false;
            if(!(x%j)) ok = true;
            while(!(x%j)){
                x /= j;
                num[i][j]++;
            }
            if(ok) cnt[j].insert(num[i][j]);
        }
        if(x != 1) num[i][x]++, cnt[x].insert(1);
    }
    ll ans = 1;
    for(int i = 2; i < N; i++){
        if(cnt[i].size() == n) ans = (ans*fexp(i,*(cnt[i].begin())))%MOD;
    }
    for(int i = 0; i < q; i++){
        int pos, x;
        scanf("%d%d", &pos, &x);
        pos--;
        for(int j = 2; j*j <= x; j++){
            int last = 0;
            bool ok = false;
            if(!(x%j)) ok = true;
            if(ok){
                if(num[pos][j]){
                    if(cnt[j].size() == n) last = *cnt[j].begin();
                    cnt[j].erase(cnt[j].find(num[pos][j]));
                }
            }
            while(!(x%j)){
                x /= j;
                num[pos][j]++;
            }
            if(ok){
                cnt[j].insert(num[pos][j]);
                if(cnt[j].size() == n) ans = (ans*fexp(j,*cnt[j].begin()-last))%MOD;
            }
        }
        if(x != 1){
            int last = 0;
            if(num[pos][x]){
                if(cnt[x].size() == n) last = *cnt[x].begin();
                cnt[x].erase(cnt[x].find(num[pos][x]));
            }
            num[pos][x]++;
            cnt[x].insert(num[pos][x]);
            if(cnt[x].size() == n) ans = (ans*fexp(x,*cnt[x].begin()-last))%MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}