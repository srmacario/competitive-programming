#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        s += t;
        sort(s.begin(), s.end());
        cout << s << "\n";
    }
}