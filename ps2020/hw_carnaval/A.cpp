#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,mult;
    cin >> a >> b >> c;
    mult = min({a,(b/2),(c/4)});
    cout << 7*mult << "\n";
    return 0;
}