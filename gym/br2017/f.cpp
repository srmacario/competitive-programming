#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;

const int N = 2e5+5;

ll n , resp , bit[N];
map<pll,ll> S;
vector<plll> vec;
queue<pll> q;

void add(ll p, ll v){
  for (p+=2; p<N; p+=p&-p) bit[p] = max(bit[p],v);
}

ll query(ll p) {
  ll r = 0;
  for (p+=2; p; p-=p&-p) r = max(r,bit[p]);
  return r;
}

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);

  cin >> n;

  for(int i = 0 ; i < n ; i++){
    ll x , y , z;
    cin >> x >> y >> z;
    S[{x,y}] += z;
  }
  for(auto v : S) vec.pb({v.st,v.nd});
  
  ll ant = 0;
  for(auto v : vec){

    if(v.st.st != ant){
      while(!q.empty()){
        pll aux = q.front();
        add(aux.st,aux.nd) , q.pop();
      }
    }
    //cout << v.st.st << " " << v.st.nd << " " << query(v.st.nd-1) << "\n";
    
    resp = max(resp,v.nd+query(v.st.nd-1)) , ant = v.st.st;
    q.push({v.st.nd,v.nd+query(v.st.nd-1)});
  
  }

  cout << resp << "\n";

}
