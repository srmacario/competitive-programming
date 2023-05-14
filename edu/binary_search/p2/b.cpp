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

int a[N], n, k, mx;

bool check(ld x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int tmp = a[i] / x;
        cnt += tmp;
    }
    return cnt >= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(a[i], mx);
    }
    ld l = 0, r = mx;
    while(r - l > EPS){
        ld mid = (r + l)/2;
        if(check(mid)) l = mid;
        else r = mid; 
    }
    cout << setprecision(15) << l << "\n";
    return 0;
}