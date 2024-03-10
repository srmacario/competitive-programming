#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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

typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set s;

int m;
vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    v.push_back(0);
    for(int i = 1; i <= m; i++){
        int op, a, b;
        cin >> op;
        if(op == 1){
            cin >> a;
            s.insert({a, i});
        }
        if(op == 2){
            cin >> b;
            s.erase({v[b], b});
        }
        if(op == 3){
            cin >> b >> a;
            s.erase({v[b], b});
            v[b] += a;
            s.insert({v[b], b});
        }
        if(op == 4){
            cin >> b;
            cout << s.order_of_key({v[b], -1}) << "\n";
        }
        v.push_back(a);
    }
    return 0;
}