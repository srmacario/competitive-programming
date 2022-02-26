#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); 
    // n muito grande, leia como string
    string n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n.size(); i++) ans += n[i] - '0';
    if((ans % 9) == 0) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}