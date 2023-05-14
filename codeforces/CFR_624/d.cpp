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
const int N = 2e4+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int rmin = INF, ra = a, rb = b, rc = c;
        for(int i=1;i<=N;i++){
            for(int j=i;j<=N;j=i+j){
                int resp1 = abs(a-i);
                int rc1 = c;
                int b1 = b, c1 = c, c2 = c;
                b1 = j;
                resp1 += abs(b-j);
                if(c%b1){
                    c1 -= c%b1, c2 += b1 - c%b1;
                    if(c%b1 < b1 - c%b1){
                        resp1 += c%b1;
                        rc1 = c1;
                    }
                    else{
                        resp1 += b1 - c%b1;
                        rc1 = c2;
                    }
                }
                if(resp1 < rmin){
                    ra = i, rb = b1, rc = rc1;
                    rmin = resp1;
                }
            }
        }
        cout << rmin << "\n" << ra << " " << rb << " " << rc << "\n";
    }
    return 0;
}