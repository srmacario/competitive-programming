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
const int N = 1e6+5;

struct rect{
    int x = 0,y = 0,a = 0;

};

bool cmp(rect a, rect b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int n, dp[N];
vector <rect> r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        rect aux;
        r.pb(aux);
        cin >> r[i].x >> r[i].y >> r[i].a;
    
    }
    sort(r.begin(),r.end(),cmp);
    int ans = -INF;
    db(dp[0]);
    for(int i=0;i<n;i++){
        dp[i] = (r[i].x*r[i].y - r[i].a);
        ans = -INF;
        for(int j=0;j<i;j++){
            ans = max(dp[j] - r[j].x*r[i].y, ans);
        }
        if(i) dp[i] += ans;
        db(dp[i]);
    }
    ans = -INF;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }
    cout << ans << "\n";
    return 0;
}