#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;

const int N = 2e5+5;

int n , x;
pii a[N];

int bs(int val){
  int l = 0 , r = n-1;
  while(l != r){
    int mid = (l+r)/2;
    if(a[mid].st < val) l = mid+1;
    else r = mid;
  }
  return l;
}

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);

  cin >> n >> x;

  for(int i = 0 ; i < n ; i++){
    int y;
    cin >> y;
    a[i] = {y,i+1};
  }
  sort(a,a+n);

  for(int i = 0 ; i < n ; i++){
    int pos = bs(x-a[i].st);
    if(pos < n && a[pos].st+a[i].st == x && a[pos].nd != a[i].nd){
      cout << a[pos].nd << " " << a[i].nd << "\n";
      return 0;
    }
  }

  cout << "-1\n";

}
