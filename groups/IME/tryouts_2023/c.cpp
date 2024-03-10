#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> x(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        long long cur = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            if(x[i] > cur) cur += x[i], cnt++;
        }
        cout << cnt << " " << cur << "\n";
    }
}