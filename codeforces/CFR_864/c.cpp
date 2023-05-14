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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int d[3];
        //ask 1, 1
        cout << "? 1 1" << endl;
        cin >> d[0];
        if(d[0] + 1 > n){
            cout << "? 1 " << d[0] + 1 << endl; 
            cin >> d[2];
            cout << "! " << d[2] + 1 << " " << d[0] + 1 << endl;
            continue;
        }
        
        //king is somewhere (r == d + 1, c <= d + 1) or (c == d + 1, r <= d + 1)
        //ask d[0] + 1, 1
        cout << "? " << d[0] + 1 << " 1" << endl;
        cin >> d[1];
        if(d[1] < d[0]){
            cout << "! " << d[0] + 1 << " " << d[1] + 1 << endl;
        }
        else{
            cout << "? 1 " << d[0] + 1 << endl; 
            cin >> d[2];
            cout << "! " << d[2] + 1 << " " << d[0] + 1 << endl;
        }
    }
    return 0;
}