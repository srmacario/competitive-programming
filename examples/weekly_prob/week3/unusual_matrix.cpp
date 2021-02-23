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
const int N = 1e3+5;

int n;
int m[2][N][N];

void fliprow(int id, int i){
    for(int j=0;j<n;j++) m[id][i][j] ^= 1;
}
void flipcol(int id, int i){
    for(int j=0;j<n;j++) m[id][j][i] ^= 1;
}

bool calc(){
    for(int j=0;j<n;j++){
        if(m[0][0][j] ^ m[1][0][j]) flipcol(0,j);
    }
    for(int i=0;i<n;i++){
        int dif = m[0][i][0] ^ m[1][i][0];
        for(int j=0;j<n;j++){
            if((m[0][i][j] ^ m[1][i][j]) ^ dif) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int k=0;k<2;k++){
            for(int i=0;i<n;i++){
                string s;
                cin >> s;
                for(int j=0;j<n;j++) m[k][i][j] = s[j] - '0';
            }
        }
        bool ans = false;
        for(int x=0;x<2;x++){
            ans = calc();
            if(ans) break;
            fliprow(0,0);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}