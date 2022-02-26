#include <bits/stdc++.h>

using namespace std;
#define PI 3.14159265

int main(){
    int n,r;
    double angle,ans;
    cin >> n >> r;
    angle = PI/n;
    ans = (r*sin(angle))/(1-sin(angle));
    cout << fixed << setprecision(7) << ans << "\n";
    return 0;
}