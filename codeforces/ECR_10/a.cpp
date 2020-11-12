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

int h1,h2,a,b,cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h1 >> h2 >> a >> b;
    while(1){
        h1 += 8*a;
        if(h1 >= h2){
            cout << cnt << "\n";
            return 0;
        }
        if(a <= b){
            cout << "-1\n";
            return 0;
        }
        cnt++;
        h1 -= 12*b;
        h1 += 4*a;
        if(h1 >= h2){
            cout << cnt << "\n";
            return 0;
        }
    }
    return 0;
}