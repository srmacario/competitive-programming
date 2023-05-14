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

const ld EPS = 1e-7, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5 + 5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set <int> a;
    int n;
    for(int i=0;i<10;i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    cin >> n;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<6;j++){
            int x;
            cin >> x;
            if(a.count(x)) cnt++;
        }
        cout << ((cnt >= 3) ? "Lucky" : "Unlucky") << "\n";
    }
    return 0;
}