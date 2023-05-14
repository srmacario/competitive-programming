#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 1e5+5;

int n, m, q;

ll mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for(int k = 0; k < q; k++){
        int a, b, c, d;
        cin >> c >> d >> a >> b;
        //odd
        ll cnt[2][2] = {0}, s[2][2] = {0}, ans = 0;
        //cnt in the same row
        if(a % 2)   cnt[0][1] = (b - a + 2)/2, cnt[0][0] = (b - a + 1) / 2;
        else        cnt[0][0] = (b - a + 2)/2, cnt[0][1] = (b - a + 1) / 2;
        //cnt in the same column
        if(c % 2)   cnt[1][1] = (d - c + 2)/2, cnt[1][0] = (d - c + 1) / 2;
        else        cnt[1][0] = (d - c + 2)/2, cnt[1][1] = (d - c + 1) / 2;
        //sum: (i - 1) * M + j
        //row contribution: j
        ll ini = a, fim = b;
        //even contribution
        if(ini % 2) ini++;
        if(fim % 2) fim--;
        s[0][0] = mul((((fim + ini) * cnt[0][0]) / 2), cnt[1][0]);
        //odd contribution
        ini = a, fim = b;
        if(!(ini % 2)) ini++;
        if(!(fim % 2)) fim--;
        s[0][1] = mul((((fim + ini) * cnt[0][1]) / 2), cnt[1][1]);

        //column contribution: (i - 1) * M
        ini = c, fim = d;
        //even contribution
        if(ini % 2) ini++;
        if(fim % 2) fim--;
        s[1][0] = mul((((fim + ini - 2) * cnt[1][0]) / 2), mul(cnt[0][0], m));
        //even contribution
        ini = c, fim = d;
        if(!(ini % 2)) ini++;
        if(!(fim % 2)) fim--;
        s[1][1] = mul((((fim + ini - 2) * cnt[1][1]) / 2), mul(cnt[0][1], m));
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++) ans = (ans + s[i][j]) % MOD;
        cout << ans << "\n";
    }
    return 0;
}