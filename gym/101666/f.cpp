#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define vi vector<int>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi a;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(),a.end(),greater<int>());
    int ans[2] = {0};
    for(int i=0;i<n;i++){
        ans[i%2] += a[i];
    }
    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}