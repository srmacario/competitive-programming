#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p,i,x,n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n--){
        cin >> x;
        if(x%2) i++;
        else p++;
    }
    cout << min(p,i) << "\n";

    return 0;
}