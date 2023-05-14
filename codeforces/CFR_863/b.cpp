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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, x[2], y[2];
        cin >> n >> x[0] >> y[0] >> x[1] >> y[1];
        int ini, fim, posini, posfim;
        ini = x[0];
        if(ini > n/2) ini = n/2 - (x[0] - n/2) + 1;
        if(y[0] <= ini) posini = y[0];
        else if(n - y[0] + 1 <= ini) posini = n - y[0] + 1;
        else posini = ini;

        fim = x[1];
        if(fim > n/2) fim = n/2 - (x[1] - n/2) + 1;
        if(y[1] <= fim) posfim = y[1];
        else if(n - y[1] + 1 <= fim) posfim = n - y[1] + 1;
        else posfim = fim;
        cout << abs(posini - posfim) << "\n";
    }
    return 0;
}