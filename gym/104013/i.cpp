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
    int s;
    cin >> s;
    for(int a = 1; a * a <= s; a++){
        for(int b = 0; b * b <= s - a * a; b++){
            if(s == a * a + b * b){
                cout << 0 << " " << 0 << "\n";
                cout << a << " " << b << "\n";
                cout << a + b << " " << b - a << "\n";
                cout << b << " " << -a << "\n";
                return 0;
            }
        }
    }
    cout << "Impossible\n";
    return 0;
}