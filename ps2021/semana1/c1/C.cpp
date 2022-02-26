#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;

const int N = 2e5+5;

int t;
ll n;
bool ok;

int bs(ll init , ll val , ll l , ll r){
  while(l != r){
    ll mid = (l+r)/2;
    if(init*init*init + mid*mid*mid < val) l = mid+1;
    else r = mid;
  }
  return l;
}

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);

  cin >> t;

  for(int z = 0 ; z < t ; z++){
    
    cin >> n;

    ll mx;
    ok = false;
    for(mx = 1 ; mx*mx*mx <= n ; mx++);

    for(ll i = 1 ; i <= mx ; i++){
      
      ll val = bs(i,n,i,mx);
      if(i*i*i+val*val*val == n){ok = true; break;}
      
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";
    
  }

}
