#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3ff3, MOD = 1e9+7;
const int N = 1e5+5;
const int M = 1e6+5;

int n, k, perf[N], ans[N];

vector<int> pos[M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> perf[i];
        pos[perf[i]].push_back(i);
    }

    for (int i = 1; i < M; i++) {
        for (auto p : pos[i]) {
            int mx = 0, p_ant = p-1, p_pos = p+1;

            if (p_pos == n) p_pos = 0;
            if (p_ant == -1) p_ant = n-1;

            if (perf[p_pos] < i) mx = max(mx, ans[p_pos]);
            if (perf[p_ant] < i) mx = max(mx, ans[p_ant]);

            ans[p] = (mx + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << 1ll * ans[i] * k;
        if(i != n - 1) 
            cout << " ";
    }
    cout << "\n";




    return 0;
}