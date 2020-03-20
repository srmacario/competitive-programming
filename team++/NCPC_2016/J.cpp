#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,dif1,dif2;
    cin >> a >> b;
    if(b == a) cout << "0\n";
    if(b < a){
        dif1 = b-a;
        dif2 = abs(360 + dif1);
        if(abs(dif2) <= abs(dif1)) cout << dif2 << "\n";
        else cout << dif1 << "\n";
    }
    if(b > a){
        dif2 = b-a;
        dif1 = dif2 - 360;
        if(abs(dif2) <= abs(dif1)) cout << dif2 << "\n";
        else cout << dif1 << "\n";
    }
    return 0;
}