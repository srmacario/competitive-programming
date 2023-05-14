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
    int n, l = 1, r = 3;
    cin >> n;
    set <int> c;
    int ok1 = 0, ok2 = 0;
    bool ok = false;
    for(int i=2;i<=n;i++){
        if(i == r) continue;
        cout << "? " << l << " " << i << " " << r << endl;
        cin >> ok1;
        if(ok1 == -1) return 0;
        if(ok1 == 0) r = i;
    }
    cout << "! " << r << "\n";
    return 0;
}