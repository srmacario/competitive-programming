#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l, r, b, k;
    cin >> l >> r >> b >> k;
    cout << ((l - 1)/b + 1) * b * k << "\n";
    return 0;
}