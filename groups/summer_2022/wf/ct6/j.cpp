#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

const ld EPS = 1e-9;
const int N = 1e3 + 5;

int n, x[N], y[N], z[N], p[N];

bool le(ld x, ld y){return x - EPS < y;}

bool check(int i, int j, ld P){
    if(i == j) return true;
    int manh = abs(x[i] - x[j]) + abs(y[i] - y[j]) + abs(z[i] - z[j]);
    if(le((ld)manh, P * (p[i] + p[j]))) return true;
    return false;
}

bool valid(ld P){
    bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ok &= check(i, j, P);
        }
    }
    return ok;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i] >> z[i] >> p[i];
        }
        ld l = 0, r = 1e9;
        while(r - l > EPS){
            ld mid = (r + l) / 2;
            if(valid(mid)) r = mid;
            else l = mid;
        }
        cout << "Case #" << k << ": " << setprecision(15) << fixed << l << "\n";
    }
    return 0;
}