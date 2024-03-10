#include <bits/stdc++.h>

using namespace std;

map<int, int> g;

int calc(int x, int k){
    if(k == 0) return x;
    if(x == 0) return (k % 2);
    string sx = to_string(x);
    int val = 0;
    for(auto ch : sx) val += g[ch - '0'];
    return calc(val, k - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    g[0] = g[4] = g[6] = g[9] = 1;
    g[8] = 2;
    while(t--){
        int x, k;
        cin >> x >> k;
        cout << calc(x, k) << "\n";
    }

    return 0;
}