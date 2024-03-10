#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 0, b = 0;
    int x, y;
    cin >> x >> y;
    a += x, b += y;
    cin >> x >> y;
    a += x, b += y;

    if(a > b) cout << "A\n";
    if(a < b) cout << "P\n";
    if(a == b) cout << "D\n";
    return 0;
}