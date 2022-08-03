#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll solve(vector<ll> h, int h_max){
    ll ans = 0;
    vector<ll> even, odd;
    for(int i = 0; i < h.size(); i++) h[i] = h_max - h[i];
    for(int i = 0; i < h.size(); i++) if(!(h[i] % 2) and h[i]) even.push_back(h[i]);
    for(int i = 0; i < h.size(); i++) if((h[i] % 2)) odd.push_back(h[i]);
    for(int i = 0; i < odd.size(); i++){
        ans += 2;
        odd[i]--;
        if(odd[i]) even.push_back(odd[i]);
        bool ok = false;
        if(even.size()){
            ll cur_even = even.back();
            even.pop_back();
            cur_even -= 2;
            if(cur_even) even.push_back(cur_even);
            ok = true;
        }
        if(i + 1 == odd.size() and ok == false) ans--;
    }
    ll sum = 0;
    for(auto x : even) sum += x;
    ans += (sum/6) * 1ll * 4;
    sum %= 6;
    if(sum == 2) ans += 2;
    if(sum == 4) ans += 3;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        sort(h.begin(), h.end());
        int gt = h.back();
        ll ans = min(solve(h, gt), solve(h, gt + 1));
        cout << ans << "\n";
    }
    return 0;
}