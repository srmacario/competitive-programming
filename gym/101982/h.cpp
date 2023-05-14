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
const int N = 1e6+10;

int cmp[N];

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,cnt = 0;
    cin >> x;
    primes();
    while(x>=4){
        for(int i=2;i<=x/2+1;i++){
            if(!cmp[i] and !cmp[x-i]){
                x -= 2*i;
                cnt++;
                break;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}