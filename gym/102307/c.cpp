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
const int N = 1e6+5;
char s1[N], s2[N];
int m[2][N], n;

int lcs () {
    for (int i = 1; i <= n; i++){
        for(int j=max(0,i-1010);j<=min(n,i+1010);j++) m[0][j] = m[1][j], m[1][j] = 0;
        for (int j =max(1,i-1010); j <= min(i+1010,n); j++){
            if (s1[i-1] == s2[j-1])
                m[1][j] = 1 + m[0][j-1];
            else
                m[1][j] = max(m[1][j-1], m[0][j]);
        }
    }
    return m[1][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin >> a >> b;
    n = a.size();
    for(int i=0;i<n;i++){s1[i+1] = a[i], s2[i+1] = b[i];}
    int ans= lcs();
    if(ans >= (n+1)*99/100) cout << "Long lost brothers D:\n";
    else cout << "Not brothers :(\n";
    return 0;
}