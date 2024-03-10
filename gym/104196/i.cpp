#include <bits/stdc++.h>

#define st first
#define nd second

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

typedef long long ll;

const int N = 105;

//round, pin/unpin, pos
int n[2][2], where[2][N], pos[N], ans;
vector<int> seq[2][2], ini_seq[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int k = 0; k < 2; k++){
        cin >> n[k][0] >> n[k][1];
        for(int i = 0; i < 2; i++){
            seq[k][i].resize(n[k][i]);
            for(int j = 0; j < n[k][i]; j++){
                cin >> seq[k][i][j];
                where[k][seq[k][i][j]] = i;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n[0][i]; j++){
            if(where[0][seq[0][i][j]] == where[1][seq[0][i][j]]){
                ini_seq[i].push_back(seq[0][i][j]);
            }
            else ans++;
        }
    }
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n[1][i]; j++){
            pos[seq[1][i][j]] = j;
        }
    }

    //forward
    int look = 0, cnt = 0;
    for(auto v : ini_seq[0]){
        if(pos[v] == look) cnt++, look++;
    }
    ans += (2 * ((int)ini_seq[0].size() - cnt));

    //backward
    look = n[1][1] - 1, cnt = 0;
    for(int i = (int)ini_seq[1].size() - 1; i >= 0; i--){
        int v = ini_seq[1][i];
        if(pos[v] == look) cnt++, look--;
    }
    ans += (2 * ((int)ini_seq[1].size() - cnt));
    cout << ans << "\n";
    return 0;
}