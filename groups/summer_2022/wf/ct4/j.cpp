#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k = 0;
    while(true){
        ++k;
        int b, c;
        cin >> b >> c;
        if(!b and !c) return 0;
        vector<vector<int>> v(b);
        vector<int> cnt(c);
        for(int i = 0; i < b; i++){
            v[i].resize(c);
            for(int j = 0; j < c; j++){
                cin >> v[i][j];
            }
        }
        //current possible winners
        int ans = -1;
        set<int> poss;
        for(int i = 0; i < c; i++) poss.insert(i);
        //iterate through each position
        for(int i = 0; i < c; i++){
            cnt.clear();
            //count points for that position
            for(int j = 0; j < b; j++){
                if(poss.count(v[j][i])) cnt[v[j][i]]++;
            }
            //retrieve max score for that phase
            int mx_score = 0;
            for(int j = 0; j < c; j++){
                if(poss.count(j)) mx_score = max(mx_score, cnt[j]);
            }
            //iterate through possible to see if they have max score
            for(int j = 0; j < c; j++){
                if(poss.count(j) and cnt[j] < mx_score) poss.erase(j);
            }
            if(poss.size() == 1){
                ans = *poss.begin();
                break;
            }
        }
        cout << "Case " << k << ": ";
        if(ans != -1){
            cout << ans << "\n";
        }
        else cout << "No Condorcet winner\n";
    }
    return 0;
}