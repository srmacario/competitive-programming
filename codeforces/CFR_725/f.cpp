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

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll l, r;
        scanf("%lld%lld", &l, &r);
        ll dif = r - l;
        ll md[20] = {0}, dv[20] = {0}, chn[20] = {0};
        ll ans = 0, i = 0, k = 0, m = 0;
        // db(dif);
        chn[0] = dif;
        while(l){
            md[k] = l%10;
            l /= 10;
            k++;
        }
        while(r){
            r /= 10;
            m++;
        }
        while(dif){
            dif /= 10;
            i++;
        }
        for(int j = 0; j < m; j++){
            ans += chn[j];
            int delta = 0;
            if(md[j] == 0) delta = 10;
            else delta = 10 - md[j];
            // db(j _ chn[j] _ delta);
            if(delta <= chn[j]){
                chn[j + 1] = 1 + (chn[j] - (delta))/10;
                // md[j+1] = (md[j+1] + chn[j + 1]) % 10;
            }
        }
        ans += chn[m];
        printf("%lld\n", ans);
    }
    return 0;
}