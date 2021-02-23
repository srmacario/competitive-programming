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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,s;
    cin >> n >> m >> s;
    vi comm;
    set<int> mk;
    comm.pb(-INF);
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        if(!mk.count(x)) mk.insert(x), comm.pb(x);
    }
    sort(comm.begin(),comm.end());
    comm.pb(INF);
    int ans = 0;
    int aux = max(1,comm[1]-m+1);
    while(aux <= min(n-m+1,comm[comm.size()-2])){
        
    }
    for(int i=max(1,comm[1]-m+1);i<=min(n-m+1,comm[comm.size()-2]);i++){
        int low = (lower_bound(comm.begin(),comm.end(),i) - comm.begin());
        int up = (upper_bound(comm.begin(),comm.end(),i+m-1) - comm.begin());
        int has = (up - low);
        if(m-has <= s) ans++;
    }
    cout << ans << "\n";
    return 0;
}