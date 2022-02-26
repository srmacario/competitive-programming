#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;

const int N = 1e5+5;

int t , n , m , a[N] , b[N] , p[N];
bool ok;

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);

  cin >> t;

  for(int z = 0 ; z < t ; z++){
    
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){cin >> a[i]; b[i] = a[i];}
    for(int i = 1 ; i <= m ; i++) cin >> p[i];
    ok = true , sort(p+1,p+m+1) , sort(b+1,b+n+1);

    for(int i = 1 ; i <= m ; i++){

      int j = i;
      while(p[i]+1 == p[i+1] && i < m) i++;
      sort(a+p[j],a+p[i]+2);

    }

    for(int i = 1 ; i <= n ; i++)
      if(a[i] != b[i]) ok = false;

    if(ok) cout << "YES\n";
    else cout << "NO\n";

  }

}
