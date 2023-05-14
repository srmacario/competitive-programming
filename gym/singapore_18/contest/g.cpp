#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e6 + 5;

bool cmp[N];
int npf[N];

void calc() {
    cmp[1] = true;
    for (int i = 2; i < N; i++) if (!cmp[i]) {
        for (int j = 2 * i; j < N; j += i) cmp[j] = true;
    }

    for (int i = 1; i < N; i++) if (cmp[i]) {
        for (int j = i; j < N; j += i) npf[j]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    calc();

    int q, n;
    cin >> q;
    while (q--) {
        cin >> n;
        cout << npf[n] << "\n";
    }

    return 0;
}