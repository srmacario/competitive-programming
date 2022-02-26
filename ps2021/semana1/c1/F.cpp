#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long ll;

const int N = 1e5+5;

int n , qtd , a[N] , resp[N];

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);

  cin >> n;

  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  sort(a+1,a+n+1);

  int cont = 0;
  for(int i = 1 ; i <= n ; i += 2) resp[i] = a[n-cont] , cont++;
  if(n%2 == 0) resp[n] = a[n-cont] , cont++;
  for(int i = 2 ; i < n ; i += 2) resp[i] = a[n-cont] , cont++;

  for(int i = 2 ; i < n ; i++) 
    if(resp[i-1] > resp[i] && resp[i] < resp[i+1]) qtd++;

  cout << qtd << "\n";
  for(int i = 1 ; i <= n ; i++) cout << resp[i] << " ";
  cout << "\n";

}
