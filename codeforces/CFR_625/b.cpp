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
const int N = 2e5+5;

ll n, s[N];
pll ps[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
        ps[i].st = s[i] - i, ps[i].nd = i;
    }
    sort(ps, ps+n);
    //for(int i=0;i<n;i++) cout << ps[i].st << "\n";
    ll ans = s[ps[0].nd], ans_now = s[ps[0].nd];
    for(int i=1;i<n;i++){
        ans = max(ans,ans_now);
        if(ps[i].st == ps[i-1].st){
            ans_now += s[ps[i].nd];
        }
        else{
            ans_now = s[ps[i].nd];
        }
        ans = max(ans,ans_now);
    }
    cout << ans << "\n";
    return 0;
}