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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        bool eq = false;
        for(int i=0;i<n;i++) cin >> a[i];
        vi ra = a;
        sort(ra.begin(), ra.end(), greater<int>());
        bool ok = false;
        for(int i=0;i<n;i++){
            if(i and (a[i] == a[i-1])) eq = true;
            if(ra[i] != a[i]) ok = true;
        }
        cout << ((ok or eq) ? "YES" : "NO") << "\n";
    }
    return 0;
}