#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define endl '\n'
#define inf 0x3f3f3f3f
 
int n, w;
ll c[102], v[102];
ll dp[103][1003];
 
//dp[a][b] -> minimum weight to achieve val=b, using itens 1 to b
 
ll peso(int i, int val){
  if(val <=0) return 0;
  if(i==0) return inf;
  if(dp[i][val]!=-1) return dp[i][val];
  return dp[i][val]=min(peso(i, val), peso(i-1, val-v[i]) + c[i]);
}
 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin >> n >> w;
  for(int i=1; i<=n; i++) cin >> c[i] >> v[i];
 
  for(int i=1; i<=n; i++){
    for(int j=1; j<=1000; j++){
      dp[i][j]=-1;
    }
  }
 
  for(int val=1000; val>=0; val--) {
    if(peso(n, val)<=w){
      cout << val << endl;
      return 0;
    }
  }
}