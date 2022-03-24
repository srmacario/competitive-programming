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
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2 + 5;

int n, k, l;
ll a[N][N], sum;
int v, x, y;
char c;

void moveR() {
    for (int i = 0; i < n; i++) {
        int k = n - 1;
        ll last = -1;
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] == 0) continue;
            if (a[i][j] == last) {
                a[i][k] = 2ll * last, k--;
                sum += last;
                last = -1;
            } else {
                if (last != -1) a[i][k] = last, k--;
                last = a[i][j];
            }
            a[i][j] = 0;
        }
        if (last != -1) a[i][k] = last;
    }
}

void moveL() {
    for (int i = 0; i < n; i++) {
        int k = 0;
        ll last = -1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) continue;
            if (a[i][j] == last) {
                a[i][k] = 2ll * last, k++;
                sum += last;
                last = -1;
            } else {
                if (last != -1) a[i][k] = last, k++;
                last = a[i][j];
            }
            a[i][j] = 0;
        }
        if (last != -1) a[i][k] = last;
    }
}

void moveD() {
    for (int j = 0; j < n; j++) {
        int k = n - 1;
        ll last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i][j] == 0) continue;
            if (a[i][j] == last) {
                a[k][j] = 2ll * last, k--;
                sum += last;
                last = -1;
            } else {
                if (last != -1) a[k][j] = last, k--;
                last = a[i][j];
            }
            a[i][j] = 0;
        }
        if (last != -1) a[k][j] = last;
    }
}

void moveU() {
    for (int j = 0; j < n; j++) {
        int k = 0;
        ll last = -1;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 0) continue;
            if (a[i][j] == last) {
                a[k][j] = 2ll * last, k++;
                sum += last;
                last = -1;
            } else {
                if (last != -1) a[k][j] = last, k++;
                last = a[i][j];
            }
            a[i][j] = 0;
        }
        if (last != -1) a[k][j] = last;
    }
}


void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> k;

    while (k--) {
        cin >> v >> x >> y;
        x--, y--;
        a[x][y] = v;
    }

    cin >> l;
    while (l--) {
        cin >> c >> v >> x >> y;
        if (c == 'L') moveL();
        if (c == 'R') moveR();
        if (c == 'U') moveU();
        if (c == 'D') moveD();
        x--, y--;
        a[x][y] = v;
    }

    cout << 2ll * sum << "\n";

    return 0;
}