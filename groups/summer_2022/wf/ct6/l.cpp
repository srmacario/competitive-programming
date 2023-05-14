#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(true){
        cin >> n;
        if(!n) return 0;
        vector<int> ord(n), side;
        for(int i = 0; i < n; i++){
            cin >> ord[i];
        }
        bool ok = true;
        for(int i = 1, j = 0; i <= n; i++){
            /*cout << i << " ";
            if(j < n) cout << ord[j] << " ";
            if(side.size()) cout << side.back();
            cout << "\n";*/
            if(side.size() and side.back() == i){
                side.pop_back();
                continue;
            }
            while(j < n and ord[j] != i){
                side.push_back(ord[j++]);
            }
            if(j == n){
                ok = false;
                break;
            }
            else j++;
        }
        if(!ok) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}