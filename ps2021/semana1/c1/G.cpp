#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;

const int N =2e5+5;

int n , r , a[N];
multiset<int> S;

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);

  cin >> n;

  for(int i = 1 ; i <= n ; i++) cin >> a[i];

  int pos = 1;
  S.insert(a[1]);
  for(int i = 2 ; i <= n ; i++){
    
    r = max(r,(int)S.size());

    while(S.count(a[i])) S.erase(S.find(a[pos])) , pos++;
    S.insert(a[i]);

  }

  r = max(r,(int)S.size());

  cout << r << "\n";

}
