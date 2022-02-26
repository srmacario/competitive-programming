#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multiset <string> all;
    string s;
    cin >> s;
    int n = s.size();
    //primeiro for percorre a posição inicial da substring
    for(int l = 0;l < n;l++){
        //o segundo for dirá o tamanho da substring
        for(int r = 3;r <= n - l;r++){
            all.insert(s.substr(l,r));
        }
        //note que só considerei tamanhos maior que 3 pois o menor nome possivel é 3
    }
    int ans = 0;
    ans += all.count("Danil");
    ans += all.count("Olya");
    ans += all.count("Slava");
    ans += all.count("Ann");
    ans += all.count("Nikita");
    cout << ((ans == 1) ? "YES\n" : "NO\n");
    return 0;
}