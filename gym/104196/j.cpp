#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int n;
map<ll, vector<int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        v[x].push_back(i + 1);
    }
    pair<ll, pair<ll, ll>> ans = {0, {0, 0}};
    set<int> cur;
    cur.insert(0), cur.insert(n + 1);
    for(auto p : v){
        ll value = p.st;
        vector<int> positions = p.nd;
        for(auto pos : positions){
            ll l, r;
            auto nxt = cur.upper_bound(pos);
            r = (*nxt) - 1;
            l = (*(--nxt)) + 1;
            ans = max(ans, make_pair(value * (r - l + 1), make_pair(-l, r)));
        }
        for(auto pos : positions) cur.insert(pos);
    }
    cout << -ans.nd.st << " " << ans.nd.nd << " " << ans.st << "\n";
    return 0;
}