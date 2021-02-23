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
const int N = 105;

int ans[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            if((!(n%i) and n/i == 2)) continue;
            for(int j=0;j<n;j++){
                ans[j][(j+i)%n] = 1;
                ans[(j+i)%n][j] = -1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cout << ans[i][j] << " ";
            }
        }
        cout << "\n";
        memset(ans,0,sizeof(ans));
    }
    return 0;
}