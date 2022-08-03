#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++){
        int v[4];
        memset(v, 63,sizeof(v));
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 4; k++){
                int x;
                cin >> x;
                v[k] = min(v[k], x);
            }
        }
        int sum = 0;
        int ans[4];
        cout << "Case #" << i << ": ";
        for(int j = 0; j < 4; j++){
            if(1000000 - sum > v[j]) ans[j] = v[j], sum += v[j];
            else ans[j] = 1000000 - sum, sum = 1000000;
        }
        if(sum != 1000000) cout << "IMPOSSIBLE\n";
        else{
            for(int j = 0; j < 4; j++) cout << ans[j] << " ";
            cout << "\n";
        }
        
    }
    return 0;
}