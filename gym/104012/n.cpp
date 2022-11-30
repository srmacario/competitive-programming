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
    string ini, fim;
    int ans = 0;
    cin >> ini >> fim;
    int h_ini = (ini[0] - '0') * 10 + (ini[1] - '0');
    int m_ini = (ini[3] - '0') * 10 + (ini[4] - '0');
    int h_fim = (fim[0] - '0') * 10 + (fim[1] - '0');
    int m_fim = (fim[3] - '0') * 10 + (fim[4] - '0');
    if(m_fim >= m_ini) ans += m_fim - m_ini;
    else{
        ans += (m_fim - m_ini + 60) % 60;
        h_ini = (h_ini + 1)%24;
    }
    ans += (h_fim - h_ini + 24) % 24;
    cout << ans << "\n";

    return 0;
}