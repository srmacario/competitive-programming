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
const ll LINF = 0x3f3f3f3f3f3f3f3fUL;
const int INF = 0x3f3f3f3fL, MOD = 1e9+7;
const int N = 1e5+5;

int n,m,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    string ans;
    for(int i=0;i<n-1;i++) ans += 'D';
    for(int i=0;i<m-1;i++) ans += 'L';
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(i%2) ans += 'L';
            else ans+= 'R';
        }
        if(i<n-1) ans+='U';
    }
    cout << ans.size() << "\n" << ans << "\n";
    return 0;
}