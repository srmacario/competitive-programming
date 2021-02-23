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
const int N = 3005;

int len1, len2;
string a, b, ans, indans;
int m[N][N];

int lcs() {
    for (int i = len1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            if (a[i-1] == b[j-1])
                m[i][j] = 1 + m[i-1][j-1];
        else
            m[i][j] = max(m[i][j-1], m[i-1][j]);
    return m[len1][len2];
}

void rec(int i, int j){
    if(!i or !j) return;
    int left = m[i][j-1], top = m[i-1][j], diag = m[i-1][j-1], now = m[i][j];
    if(now - diag == 0){
        rec(i-1, j-1);
    }
    else if(now - left == 0){
        rec(i, j-1);
    }
    else if(now - top == 0){
        rec(i-1, j);
    }
    else if(now - diag == 1){
        ans += a[i-1];
        indans += i-1 + '0';
        rec(i-1, j-1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    len1 = a.size(), len2 = b.size();
    lcs();
    int aux = 0;
    rec(len1,len2);
    for(int i=ans.size()-1;i>=0;i--) cout << ans[i];
    for(int i=ans.size()-1;i>=0;i--) cout << indans[i];
    cout << "\n";
    return 0;
}