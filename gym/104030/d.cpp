#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define nd second
#define st first

const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r, x;
    pair<ll, pair<ll, ll>> ans = {LINF, {0, 0}};
    cin >> r;
    x = r + 1;
    for(ll y = 0; y <= r; y++){
        while((x - 1) * (x - 1) + y * y > r * r) x--;
        ans = min(ans, make_pair(x * x + y * y, make_pair(x, y)));
    }
    cout << ans.nd.st << " " << ans.nd.nd << "\n";
    return 0;
}