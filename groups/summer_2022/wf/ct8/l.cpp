#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int ts, tp, x, vis[N][N][30], dp[N][N][30];
char s[N], p[N];

int calc(int p1, int p2, int c){
    c = max(0, c);
    c = min(25, c);
    if(p2 == tp){
        dp[p1][p2][c] = ts - p1;
        cout << p1 << " " << p2 << " " << (char)(c + 'a') << " " << dp[p1][p2][c] << "\n";
        return dp[p1][p2][c];
    }
    if(p1 == ts){
        cout << p1 << " " << p2 << " " << (char)(c + 'a') << "\n";
        return dp[p1][p2][c] = tp - p2;
    }
    if(vis[p1][p2][c] == x)
        return dp[p1][p2][c];
    vis[p1][p2][c] = x;
    if(c == p[p2] - 'a')
        return dp[p1][p2][c] = calc(p1 + 1, p2 + 1, s[p1 + 1] - 'a');
    dp[p1][p2][c] = min({calc(p1 + 1, p2, s[p1 + 1] - 'a'), calc(p1, p2 + 1, c), calc(p1 + 1, p2 + 1, s[p1 + 1] - 'a')});
    if(p1 + 1 < ts && s[p1 + 1] == p[p2])
        dp[p1][p2][c] = min(dp[p1][p2][c], calc(p1 + 1, p2 + 1, c));
        return ++dp[p1][p2][c];
}

int main(){
 scanf(" %s", s);
 scanf(" %s", p);
 while(s[0] != '*'){
  x++;
  ts = strlen(s);
  tp = strlen(p);
  cout << ts << " " << tp << "\n";
  printf("%d\n", calc(0, 0, s[0] - 'a'));
  scanf(" %s", s);
  scanf(" %s", p);
 }
 return 0;
}