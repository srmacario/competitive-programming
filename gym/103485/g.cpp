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
const int N = 1e6+5;

int n, k, p[N], cnt;
ll ans[N], resp;
map <int, int> s;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);
    for(int r = 0, l = 0; r < n; r++){
        if(s[p[r]] or (l > 0 and p[r] == p[l - 1])){
            ans[r] = ans[r - 1];
        }
        if(!s[p[r]]) cnt++;
        s[p[r]]++;
        while(cnt >= k){
            if(cnt == k) ans[r]++;
            s[p[l]]--;
            if(!s[p[l]]) cnt--;
            l++;
        }
        resp += ans[r];
    }
    printf("%lld\n", resp);
    return 0;
}