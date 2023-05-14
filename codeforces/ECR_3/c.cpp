#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

int n;
vector<ll> m,dif;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll sum = 0;
    for(int i=0;i<n;i++){
        ll k;
        cin >> k;
        m.pb(k);
        sum+=k;
    }
    sort(m.begin(),m.end());
    ll med = sum/n;
    ll low = 0,up = 0,cnt = 0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(m[i] < med) low += abs(med - m[i]);
        else if(m[i] > med) up += abs(med - m[i]), cnt++;
    }
    //cout << low << " " << up << " " << cnt;
    ans += low;
    if(up - low > cnt) ans += up - low - cnt;
    cout << ans << "\n";
    return 0;
}