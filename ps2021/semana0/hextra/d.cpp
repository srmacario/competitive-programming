#include <bits/stdc++.h>

using namespace std;

map<string,int> m;
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        m[s]++;
    }
    cout << "AC x " << m["AC"] << "\n";
    cout << "WA x " << m["WA"] << "\n";
    cout << "TLE x " << m["TLE"] << "\n";
    cout << "RE x " << m["RE"] << "\n";
    return 0;
}