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
    int n;
    cin >> n;
    int grid[15][15] = {0};
    bool ok = true;
    for(int i=0;i<n;i++){
        int d,l,r,c;
        cin >> d >> l >> r >> c;
        if(!d){
            if(r >=1 and r <= 10 and c>=1 and (c+l-1)<=10){
                for(int i=c;i<=c+l-1;i++){
                    grid[r][i]++;
                    if(grid[r][i] > 1) ok = false;
                }
            }
            else ok = false;
        }
        else{
            if(r >=1 and (r+l-1) <= 10 and c>=1 and c<=10){
                for(int i=r;i<=r+l-1;i++){
                    grid[i][c]++;
                    if(grid[i][c] > 1) ok = false;
                }
            }
            else ok = false;
        }
    }
    cout << (ok ? "Y\n" : "N\n");
    return 0;
}