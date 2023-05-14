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

int n,k;
ll grid[10][10];
vi cit;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(i>1)cit.pb(i);
        for(int j=1;j<=n;j++)
            cin >> grid[i][j];
    }
    do{
        int cur = 1;
        //cout << cur << " ";
        ll dist = 0;
        for(int i=0;i<n-1;i++){
            dist += grid[cur][cit[i]];
            cur = cit[i];
            //cout << cur << " ";
        }
        dist += grid[cur][1];
        if(dist == k) ans++;
        //cout << "1\n";
    }
    while(next_permutation(cit.begin(),cit.end()));
    cout << ans << "\n";
    return 0;
}