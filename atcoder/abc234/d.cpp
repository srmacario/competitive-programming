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
const int N = 5e5+5;

int p[N], cur;
priority_queue<int> lo;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < k; i++) lo.push(-p[i]);
    cout << -lo.top() << "\n";
    for(int i = k; i < n; i++){
        if(-p[i] < lo.top()) lo.pop(), lo.push(-p[i]);
        cout << -lo.top() << "\n";
    }
    return 0;
}