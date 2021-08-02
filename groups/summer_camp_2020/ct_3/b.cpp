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
int xmax = 6, xmin = 1, ymax = 5;

pll solve(int x, int y){
    int xmax = 6, xmin = 1, ymax = 5;
    int ansx = 7-x, ansy = 5-y;
    ansx = min(ansx,6);
    ansx = max(ansx,1);
    ansy = min(ansy,5);
    ansy = max(ansy,1);
    return {ansx,ansy};
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        string s;
        cout << "5 1 5 6" << endl;
        cin >> s;
        while(s!= "GAME"){
            ll xa, ya, xb, yb;
            cin >> ya >> xa >> yb >> xb;
            vector <pll> ans;
            ans.pb(solve(xa,ya));
            ans.pb(solve(xb,yb));
            sort(ans.begin(),ans.end());
            cout << ans[0].nd << " " << ans[0].st << " " << ans[1].nd << " " << ans[1].st << endl;
            cin >> s;
        }
    }
    return 0;
}