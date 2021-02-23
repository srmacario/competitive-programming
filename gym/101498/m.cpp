#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const int N = 1e6+5;

int t , n , dist[N] , A[N] , P[N];

bool ok = false;

void bt(int x , int y , int pos){
    bool ok1 = true, ok2 = true;
    vi cur;
    if(ok) return;
    if(y-x == 1){
        if(!dist[P[y]-P[x]]) return;
        for(int i=1;i<=n;i++) cout << P[i] << " ";
        cout << "\n";
        ok = true;
        return;
    }
    for(int i=1;i<=x;i++){
        if(!dist[abs(A[pos] - P[i])]){
            ok1 = false;
            break;
        }
        dist[abs(A[pos] - P[i])]--;
        cur.pb(abs(A[pos] - P[i]));
    }
    if(ok1){
        P[x+1] = P[n] - A[pos];
        bt(x+1,y,pos-1);
        for(int i=0;i<cur.size();i++) P[cur[i]]++;
        cur.clear();
    }
    for(int i=n;i>=y;i--){
        if(!dist[abs(A[pos] - P[i])]){
            ok2 = false;
            break;
        }
        dist[abs(A[pos] - P[i])]--;
        cur.pb(abs(A[pos] - P[i]));
    }
    if(ok2){
        P[y-1] = A[pos];
        bt(x,y-1,pos-1);
        for(int i=0;i<cur.size();i++) P[cur[i]]++;
        cur.clear();
    }
}

int main(){

  ios_base::sync_with_stdio(0),cin.tie(0);

  cin >> t;

  for(int z = 0 ; z < t ; z++){

    cin >> n;
    for(int i = 1 ; i <= (n*(n-1))/2 ; i++){cin >> A[i]; dist[A[i]]++;}
    sort(A+1,A+(n*(n-1))/2+1);
    P[1] = 0 , P[n] = A[(n*(n-1))/2] , dist[A[(n*(n-1))/2]]--;
    ok = false , bt(1,n,(n*(n-1))/2-1);

  }

}