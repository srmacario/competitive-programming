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

vector <plll> c;
ll n, x, y;

bool cmp(plll a, plll b){
    ld da = sqrt((a.nd.st - x)*(a.nd.st - x) + (a.nd.nd - y)*(a.nd.nd - y)) - a.st;
    ld db = sqrt((b.nd.st - x)*(b.nd.st - x) + (b.nd.nd - y)*(b.nd.nd - y)) - b.st;
    if(abs(da - db) < EPS) return a.st > b.st;
    return da < db;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    c.resize(n);
    for(int i=0;i<n;i++){
        cin >> c[i].nd.st >> c[i].nd.nd >> c[i].st;
    }
    sort(c.begin(),c.end(),cmp);
    ld cur = 0, bg = 0;
    for(int i=0;i<n;i++){
        ld d = sqrt((c[i].nd.st - x)*(c[i].nd.st - x) + (c[i].nd.nd - y)*(c[i].nd.nd - y)) - c[i].st - cur;
        //db(d);
        if(d + EPS > 0) {
            bg += d;
            cur += d;
        }
        cur += c[i].st;
        //db(bg), db(cur);
    }
    cout << fixed << setprecision(10) << bg << "\n";
    return 0;
}