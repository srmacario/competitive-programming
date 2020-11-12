#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n, maxx = -INF, maxy = -INF, minx = INF, miny = INF;
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                ll xa,ya;
                cin >> xa >> ya;
                maxx = max(xa,maxx);
                minx = min(xa,minx);
                maxy = max(ya,maxy);
                miny = min(ya,miny);
            }
        }
        //cout << maxx << " " << minx << " " << maxy << " " << miny << "\n";
        ll ans = (maxx-minx)*(maxy-miny);
        cout << ans << "\n";
    }
    return 0;
}