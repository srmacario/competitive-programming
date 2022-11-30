#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long double ld;
const ld PI = acos(-1.);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ld ans = 0;
        int a, b, r, d;
        cin >> a >> b >> r >> d;
        if(d >= 90){
            ans = sqrt(ld(b * b) + ld((a + r) * (a + r))) - ld(r);
        }
        else{
            ld angle = (ld(b) / (ld(a + r)));
            ld d_ang = ld(d) * (PI / 180);
            if(tan(d_ang) < angle){
                ld e = ld((a + r)) / cos(d_ang);
                ld c = (tan(d_ang) * ld(a + r));
                ans = (c * (b - c)) / e + e - ld(r);
            }
            else{
                ans = sqrt(ld(b * b) + ld((a + r) * (a + r))) - ld(r);
            }
        }
        cout << setprecision(15) << fixed << ans << "\n";
    }
}