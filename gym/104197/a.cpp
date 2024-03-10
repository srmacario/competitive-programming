#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        deque<ll> dq;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        dq.push_back(a[0]);
        for(int i = 1; i < n; i++){
            ll l = dq.front(), r = dq.back();
            if(l > r) dq.push_front(a[i]);
            else dq.push_back(a[i]);
        }
        ll cur = dq.back(), ans = 0;
        for(auto d : dq){
            ans += d * cur;
            cur = d;
        }
        cout << ans << "\n";
    }
    return 0;
}