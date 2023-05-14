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
const int N = 2e5+10;

vi im1, im2, ps1, ps2;

vi Z (vi q){
    vi z(q.size());
    for(int i=1, l = 0, r = 0, n = q.size(); i<n; i++){
        if(i <= r) z[i] = min(z[i-l], r-i+1);
        while (i + z[i] < n and q[z[i]] == q[z[i] + i]) z[i]++;
        if(i + z[i] - 1 > r){
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        im1.pb(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        im2.pb(x);
    }
    sort(im1.begin(),im1.end());
    sort(im2.begin(),im2.end());
    for(int i=1;i<n;i++){
        ps1.pb(im1[i]-im1[i-1]);
        ps2.pb(im2[i]-im2[i-1]);
    }
        ps1.pb(- im1[n-1] + im1[0] + 360000);
        ps2.pb(- im2[n-1] + im2[0] + 360000);
    for(int i=0;i<n-1;i++){
        ps1.pb(ps1[i]);
    }

    vi match;
    for(int i=0;i<n;i++) match.pb(ps2[i]);
    match.pb(-1);
    for(int i=0;i<2*n-1;i++) match.pb(ps1[i]);
    //for(int i=0;i<match.size();i++) cout << match[i] << " ";
    vi ans = Z(match);
    for(int i=0;i<ans.size();i++){
        //cout << ans[i] << " ";
        if(ans[i] == n){
            cout << "possible\n";
            return 0;
        }
    }
    cout << "impossible\n";
    return 0;
}