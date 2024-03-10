#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 100 << 6;

string g[2];

int s[105], dp[105][16], n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 2; i++){
        cin >> g[i];
        n = g[i].length();
        for(int j = 0; j < n; j++) s[j] += ((g[i][j] == 'X') << i);
    }
    for(int i = 0; i < n; i++){
        //iterate through all possible ways to arrive at position i
        for(int previous_state = 0; previous_state < 4; previous_state++){
            //check if it is a permitted way
            if(previous_state & s[i]) continue;
            int current_state = previous_state | s[i];

            //impact next dp

            //without adding horse
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][previous_state]);

            //adding horse
            if(current_state == 0){
                dp[i + 1][3] = max(dp[i + 1][3], dp[i][previous_state] + 1);
                dp[i + 1][2] = max(dp[i + 1][2], dp[i][previous_state] + 1);
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][previous_state] + 1);
            }
            if(current_state == 1 or current_state == 2){
                dp[i + 1][3] = max(dp[i + 1][3], dp[i][previous_state] + 1);
            }
        }
    }

    //answer should be state where no bit is set, it means it didn't "overflowed" the board
    cout << dp[n][0] << "\n";
    return 0;
}