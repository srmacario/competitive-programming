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
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int carry = 1, bg;
        for(int i=0;i<n-1;i++){
            bg = carry;
            for(int j=0;j<m;j++){
                cout << (bg ? "B" : "W");
                bg = bg^1; 
            }
            cout << "\n";
            carry = carry^1;
        }
        bool ok = true;
        bg = carry;
        for(int j=0;j<m;j++){
            if(ok and !bg and !((n*m)%2)){
                cout << "B";
                ok = false;
            }
            else cout << (bg ? "B" : "W");
            bg = bg^1; 
        }
        cout << "\n";
    }
    return 0;
}