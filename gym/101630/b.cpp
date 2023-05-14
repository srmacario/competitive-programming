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


ll sz[3], ini[3], h,w,htmp, wtmp;

bool tst(int a, int b, int c){
    bool ok  = false;
    sz[0] = a, sz[1] = b, sz[2] = c;
    htmp = 2*(sz[0] + sz[1]), wtmp = 2*sz[0] + sz[2];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    htmp = 2*(sz[0] + sz[1]), wtmp = sz[0] + sz[1] + sz[2];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    htmp = 2*(sz[0] + sz[1]), wtmp = 2*sz[1] + sz[2];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    htmp = 2*(sz[0] + sz[1]), wtmp = sz[0] + sz[1] + sz[2];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    htmp = 2*(sz[0] + sz[1]), wtmp = sz[0] + sz[2] + sz[1];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    htmp = 2*(sz[1]) + sz[0] + sz[2], wtmp = 2*sz[0] + sz[2];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    htmp = 2*(sz[1]) + sz[0]+ sz[2], wtmp = sz[1] + sz[0] + sz[2];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    htmp = 3*(sz[1]) + sz[0] + sz[2], wtmp = sz[0] + sz[2];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    htmp = sz[0] + sz[1] + 2*sz[2], wtmp = sz[0] + sz[1] + sz[2];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    htmp = sz[0] + 2*sz[1] + sz[2], wtmp = 2*sz[0] + sz[2];
    if(htmp <= h and wtmp <= w) ok = true;
    swap(htmp,wtmp);
    if(htmp <= h and wtmp <= w) ok = true;
    return ok;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> ini[0] >> ini[1] >> ini[2] >> h >> w;
    bool ok = false;
    if(tst(ini[0],ini[1],ini[2])) ok = true;
    if(tst(ini[0],ini[2],ini[1])) ok = true;
    if(tst(ini[1],ini[0],ini[2])) ok = true;
    if(tst(ini[1],ini[2],ini[0])) ok = true;
    if(tst(ini[2],ini[0],ini[1])) ok = true;
    if(tst(ini[2],ini[1],ini[0])) ok = true;

    cout << (ok ? "Yes\n" : "No\n");

    return 0;
}