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
const int N = 5e3+5;
char s1[N], s2[N];
int m[N][N], len1, len2;
int ans;

void lcs () {
    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            if (s1[i-1] == s2[j-1])
                m[i][j] = m[i-1][j-1]+2;
            else
                m[i][j] = max({m[i][j-1]-1, m[i-1][j]-1, 0});
            ans = max(m[i][j],ans);
        }
    }
}

int main(){
    scanf("%d %d %s %s", &len1, &len2, s1, s2);
    lcs();
    cout << ans << "\n";
    return 0;
}