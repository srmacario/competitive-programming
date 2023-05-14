#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int,int>
#define piii <int,pii>
const ld EPS = 1e-7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ld X, v;
    cin >> n >> X >> v;
    ld dwalk = 0, u;
    ld l, r;
    for(int i=0;i<n;i++){
        cin >> l >> r >> u;
        dwalk += u*(r-l);
    }
    ld sen = -(dwalk/v)/X;
    if(abs(sen) > 1 - EPS){
        cout << "Too hard\n";
        return 0;
    }
    ld cos = sqrt(1 - sen*sen);
    ld tm = (X)/(v*cos);
    if(tm > 2*(X/v) + EPS) cout << "Too hard\n";
    else cout << fixed << setprecision(3) << tm << "\n";
    return 0;
}