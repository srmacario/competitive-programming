#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;

const int N = 2e5+5;

int n , q , b[N];

int bs(int val){
  int l = 0 , r = n;
  while(l != r){
    int mid = (l+r)/2;
    if(b[mid] <= val) l = mid+1;
    else r = mid;
  }
  return l;
}

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);

  cin >> n;

  for(int i = 0 ; i < n ; i++) cin >> b[i];
  sort(b,b+n);

  cin >> q;

  for(int i = 0 ; i < q ; i++){
    int x;
    cin >> x;
    cout << bs(x) << "\n";
  }

}
