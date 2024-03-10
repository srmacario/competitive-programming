#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cer << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, M;
    cin >> r >> M;
    for(int i = 0; i < M; i++){
        int n, k;
        cin >> n >> k;
        vector<int> ans, m(k);
        for(int j = 0; j < k; j++) cin >> m[j];
        ans = e(m, n, k, r);
        for(int j = 0; j < k; j++) cout << ans[j] << (j == k - 1 ? "" : " ");
        cout << "\n";
    }
}