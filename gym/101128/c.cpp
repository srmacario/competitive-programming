#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while(t--) {
    ll n,x, sum = 0;
    priority_queue <ll> pq;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x, pq.push(-x);
    //doing reverse: everyone is painted and I want to choose the best option to merge into one color
    //size 1 means everyone is already in same color
    while(pq.size() > 1){
      ll k = 0;
      //merging the smallest into k
      k += -pq.top();
      pq.pop();
      k += -pq.top();
      pq.pop();
      sum += (k);
      //reinserting k into queue
      pq.push(-k);
    }
    cout << sum << "\n";
  }
}
