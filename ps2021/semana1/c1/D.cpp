#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;

const int N = 1e5+5;

int n , tam;
vector<int> a[5];

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);
  
  cin >> n;

  for(int i = 1 ; i <= n ; i++){
    int x;
    cin >> x;
    a[x].pb(i);
  }

  tam = min(a[1].size(),min(a[2].size(),a[3].size()));

  cout << tam << "\n";
  for(int i = 0 ; i < tam ; i++)
    cout << a[1][i] << " " << a[2][i] << " " << a[3][i] << "\n";

}
