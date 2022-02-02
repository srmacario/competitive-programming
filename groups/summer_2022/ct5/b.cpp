#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        string a, b, c;
        cin >> a;
        if(a == "0") return 0;
        cin >> b;
        int pos = 0;
        for(int i = 0; i < b.size(); i++){
            c += ((b[i] - 'A') + (a[pos] - 'A') + 1)%26 + 'A';
            pos = (pos + 1)%a.size(); 
        }
        cout << c << "\n";
    }
    return 0;
}