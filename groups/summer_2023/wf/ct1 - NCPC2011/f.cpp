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
const int N = 2e5+5;

int k, n, moose[N], w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;
    priority_queue<int> pq;
    for(int i = 1; i <= n + k - 1; i++){
        int y, s;
        cin >> y >> s;
        if(y == 2011) pq.push(s);
        else moose[y] = s;
        if(i == 1) w = s;
    }
    int cur_year = 2011;
    for(int i = 0; i <= n - 1; i++){
        int winner = pq.top();
        pq.pop();
        if(winner == w){
            cout << cur_year << "\n";
            return 0;
        }
        cur_year++;
        pq.push(moose[cur_year]);
    }
    cout << "unknown\n";
    return 0;
}