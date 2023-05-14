#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> dist, ps;
        dist.push_back(0), ps.push_back(0);
        for(int i = 1; i < n; i++){
            int d;
            cin >> d;
            dist.push_back(d);
            ps.push_back(ps[i - 1] + d);
        }
        ps.push_back(ps.back());
        dist.push_back(0);
        int l = 1, r = n - 1;
        ll ans = 0, sum = 0;
        for(int k = 1; k <= n; k++){
            if(k % 2){
                ans += sum;
            }
            else {
                sum += ps[r] - ps[l - 1];
                r--, l++;
                ans += sum;
            }
            cout << ans;
            if(k != n) cout << " ";
        }
        cout << "\n";
    }
}