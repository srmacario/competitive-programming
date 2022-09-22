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
const int N = 2e5+5;

int n;
int p[N], good[N];

int calc_d(int cur, int new_pos){
    if(cur <= new_pos) return (new_pos - cur);
    return (n - cur + new_pos);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int id;
        cin >> id;
        p[id] = i;
    }
    for(int i = 0; i < n; i++){
        good[calc_d(p[i], i)]++;
        good[calc_d(p[i], i - 1)]++;
        good[calc_d(p[i], i + 1)]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, good[i]);
    cout << ans << "\n";
    return 0;
}