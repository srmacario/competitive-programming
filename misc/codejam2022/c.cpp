#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++){
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        vector<int> v(n);
        for(int j = 0; j < n; j++) cin >> v[j];
        sort(v.begin(), v.end());
        int cur = v[n - 1] - 1, ans = 1;
        for(int j = n - 2; j >= 0; j--){
            // cout << cur << "\n";
            if(cur == 0) break;
            if(cur >= v[j]) ans++, cur = v[j] - 1;
            else if(cur < v[j]) ans++, cur--;
        }
        cout << ans << "\n";
    }
    return 0;
}