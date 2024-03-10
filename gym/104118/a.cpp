#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5 + 5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    if(x <= -3) cout << -(x + 4) * (x + 4) + 8 << "\n";
    if(x > -3 and x <= 2) cout << -2 * x + 1 << "\n";
    if(x > 2) cout << x * x * x - 14 * x + 17  << "\n";
    return 0;
}