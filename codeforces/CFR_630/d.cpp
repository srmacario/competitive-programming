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
const int N = 505;

int k, a[N][N], memo[N][N];

void dp(){
    memo[0][1] = a[1][1];
    for(int i=1;i<=3;i++){
        for(int j=1;j<=4;j++){
            memo[i][j] = max(memo[i-1][j]&a[i][j],memo[i][j-1]&a[i][j]);
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    cout << "3 4\n";
    int cnt = 0;
    if(!(k%2)) k++, cnt++;
    a[1][1] = k;
    for(int i = 31;i>=0;i--){
        if((1ll << i) & k){
            a[1][1] += (1ll << (i+1));
            a[2][1] = (1ll << (i+1));
            break;
        }
    }
    a[3][1] = a[3][2] = a[3][3] = a[1][1];
    a[1][2] = a[1][3] = a[2][3] = a[3][4] = k;
    a[2][4] = cnt;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=4;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    //dp();
    return 0;
}