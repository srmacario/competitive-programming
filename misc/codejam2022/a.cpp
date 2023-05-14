#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++){
        int r, c;
        cin >> r >> c;
        cout << "Case #" << i << ":\n";
        for(int j = 0; j < 2 * r + 1; j++){
            if(!(j%2)){
                for(int k = 0; k < 2*c + 1; k++){
                    if(j == 0 and k <= 1) cout << ".";
                    else if(!(k%2)) cout << "+";
                    else cout << "-";
                }
            }
            else{
                for(int k = 0; k < 2*c + 1; k++){
                    if(j == 1 and k <= 1) cout << ".";
                    else if(!(k%2)) cout << "|";
                    else cout << ".";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}