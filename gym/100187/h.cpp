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

int x[2][3], y[2][3], l[2][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++) cin >> x[i][j] >> y[i][j];
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            l[i][j] = (x[i][j] - x[i][(j+1)%3])*(x[i][j] - x[i][(j+1)%3]) + (y[i][j] - y[i][(j+1)%3])*(y[i][j] - y[i][(j+1)%3]);
        }
    }
    sort(l[0], l[0] + 3);
    sort(l[1], l[1] + 3);
    double razao[3] = {0};
    bool ok = true;
    for(int j = 0; j < 3; j++){
        if(l[0][j] < l[1][j]){
            swap(l[0][0], l[1][0]);
            swap(l[0][1], l[1][1]);
            swap(l[0][2], l[1][2]);
            break;
        }
    }
    for(int j = 0; j < 3; j++)if(l[0][j] * l[1][0] != l[1][j] * l[0][0]){
            ok = false;
            break;
        }

    if(ok){
        if(razao[0] == razao[1] and razao[1] == razao[2]){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}