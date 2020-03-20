#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

char grid[100][100], ans[100][100];

ll quad(ll x){
    ll l=0, r= x;
    while(l<=r){
        ll mid = (l+r)/2;
        if(mid*mid == x) return mid;
        if(mid*mid > x) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        cl(grid,0);
        string s;
        cin >> s;
        ll n = quad(s.size()), cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = s[cnt];
                cnt++;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                cout << grid[j][i];
            }
        }
        cout << "\n";
    }
    return 0;
}