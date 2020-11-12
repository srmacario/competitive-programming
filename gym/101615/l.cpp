#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k,p,x, pm, tm;
    ld dk,dp,dx;
    cin >> k >> p >> x;
    pm = sqrt(((ld)k*(ld)p)/(ld)x);
    tm = pm + 1;
    ld pans, tans;
    pans = ((ld)k/(ld)pm)*(ld)p + (ld)x*(ld)pm;
    tans = ((ld)k/(ld)tm)*(ld)p + (ld)x*(ld)tm;
    if(pans < tans) cout << fixed << setprecision(3) << pans << "\n";
    else cout << fixed << setprecision(3) << tans << "\n";
    return 0;
}