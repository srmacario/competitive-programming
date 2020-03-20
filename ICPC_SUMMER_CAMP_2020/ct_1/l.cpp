#include <bits/stdc++.h>

#define ll long long
const ll N = 1e3+5;

using namespace std;

ll grid[N][N],ps[N][N],n,m;

bool is_valid(ll targ){
    for(ll i = targ; i<=n; i++){
        for(ll j = targ; j<=m; j++){
            ll ans = grid[i][j] - grid[i-targ][j] - grid[i][j-targ+1] + grid[i-targ][j-targ+1];
            if(!(ans)) {
                //cout << ans << "\n";
                return true;
            }
        }
    }
    return false;
}

ll uppe(ll l, ll r){
    ll mid;
    while(l < r){
        mid = (l+r+1)/2;
        if(!is_valid(mid)) r = mid-1;
        else l = mid;
    }
    return (is_valid(l)) ? l : -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            char x;
            cin >> x;
            if(x == 'G') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    for(ll i=n;i>=1;i--){
        for(ll j=m;j>=1;j--){
            grid[i][j] = grid[i][j]^grid[i][j-1];
            if(j == 1) grid[i][j] = 0;
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }
    }
    ll ans = uppe(1,min(n,m));
    cout << ans*ans << "\n";
    return 0;
}