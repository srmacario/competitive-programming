#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5+5;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int gcd = a[0];
    for(int i = 1; i < a.size(); i++){
        if(a[i]/2 < gcd) gcd /= 2;
    }
    cout << gcd << "\n";
    return 0;
}