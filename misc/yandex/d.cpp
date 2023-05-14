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

const ld EPS = 1e-7, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5 + 5;
vector<ll> a,b;
ll n, m, mx, ini = 1, fim = 1, pre, suf, mxb, carry, cnt, aux;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a.resize(n+5), b.resize(m+5);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre += a[i];
        if(a[i] > mx) mx = a[i], ini = i, fim = i;
        if(a[i] == mx) fim = i;
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
        suf += b[i];
        mxb = max(mxb,b[i]);
    }
    pre += (m-1)*mx;
    suf += (ini-1)*b[1] + (fim - ini)*mxb + (n-fim)*b[m];
    aux = suf;
    string p, s, ans;
    while(aux){
        s += '0' + aux%10;
        aux/=10;
    }
    aux = pre;
    if(mx) for(int i=0;i<9;i++) p += "0";
    if(!mx and !mxb) p += '0';
    while(aux){
        p += '0' + aux%10;
        aux/=10;
    }
    while(cnt < max(s.size(),p.size())){
        int d1 = 0, d2 = 0, num = 0;
        if(cnt < s.size()) d1 = s[cnt] - '0';
        if(cnt < p.size()) d2 = p[cnt] - '0';
        num = carry + d1 + d2;
        ans += (num%10) + '0';
        carry = num/10;
        cnt++;
    }
    if(carry) ans += carry + '0';
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
    return 0;
}