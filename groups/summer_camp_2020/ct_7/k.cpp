#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll C,n,cnow;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok = true;
    cin >> C >> n;
    for(int i=0;i<n;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        cnow -= a;
        if(cnow < 0) ok = false;
        cnow += b;
        if(cnow > C) ok = false;
        if(c and cnow < C) ok = false;
        if(i == n-1){
            if(c) {ok = false; continue;}
            if(cnow){ ok = false; continue;}
        }
    }
    if(ok) cout << "possible\n";
    else cout << "impossible\n";
    return 0;
}