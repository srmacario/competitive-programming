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
const int N = 1e5+5;

struct point{
    int x, y;

    point(int a = 0, int b = 0): x(a), y(b){}

    bool operator <(const point &p) const {
        return (x < p.x) or (x == p.x and y < p.y);
    }
};

ld calc(point l, point r, int pos_y){
    //y = mx + n;
    ld m = (r.y - l.y)/(r.x - l.x);
    ld n = r.y - m * r.x;
    return (1.0 * pos_y - n) / m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    cout << s;
    return 0;
}