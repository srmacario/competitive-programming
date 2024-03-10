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
const int N = 1e6+5;

int s[N], p[N], b[N], n, m, cnt;

void kmppre(){
    b[0] = -1;
    for (int i = 0, j = -1; i < m; b[++i] = ++j)
        while (j >= 0 and p[i] != p[j])
            j = b[j];
}

void kmp() {
    for (int i = 0, j = 0; i < n; ){
        while (j >= 0 and s[i] != p[j]) j = b[j];
        i++, j++;
        if(j == m){
            cnt++;
            j = b[j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    vector<int> x(m), y(n);
    for(int i = 0; i < m; i++){
        cin >> x[i];
        if(i)
            p[i - 1] = x[i] - x[i - 1];
    }
    for(int i = 0; i < n; i++){
        cin >> y[i];
        if(i)
            s[i - 1] = y[i] - y[i - 1];
    }
    if(m == 1){
        cout << n << "\n";
        return 0;
    }
    m--, n--;
    kmppre();
    kmp();

    cout << cnt << "\n";
    return 0;
}
