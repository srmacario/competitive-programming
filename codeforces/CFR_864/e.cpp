#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e3 + 5;

int n, m;

int phi[N], par[N];
set<int> adj[N];
void totient() {
  for (int i = 1; i < N; ++i)  phi[i]=i;
  for (int i = 2; i < N; i+=2) phi[i]>>=1;
  for (int j = 3; j < N; j+=2) if (phi[j]==j) {
    phi[j]--;
    for (int i = 2*j; i < N; i+=j) phi[i]=phi[i]/j*(j-1);
  }
  for (int i = 1; i < N; ++i) par[i] = phi[i], adj[phi[i]].insert(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    totient();
    vector<int> num;
    for(int i = 0; i <= 50; i++) num.push_back(i);
    for(int i = 1; i <= 10; i++){
        cout << i << "\n";
        for(auto v : adj[i]) cout << v << " ";
        cout << "\n";
    }
    cout << "\n";
    
    return 0;
}