#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll x[2], y[2];
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        ld a = ((y[0] * x[1]) - (y[1] * x[0])) / (ld)(x[0] * x[0] * x[1] - x[1] * x[1] * x[0]);
        ld b = ((y[0] * x[1] * x[1]) - (y[1] * x[0] * x[0])) / (ld)(x[0] * x[1] * x[1] - x[1] * x[0] * x[0]);
        cout << setprecision(15) << fixed << (-b / a) << "\n";
    }
    return 0;
}