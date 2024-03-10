#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x, y, v, t;
        cin >> x >> y >> v >> t;
        if(sqrt(x*x + y*y) < v * t) cout << "YES\n";
        else cout << "NO\n";
    }
}