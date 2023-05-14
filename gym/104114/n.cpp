#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, m, s[N];
set<pii> ord;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        ord.insert({s[i], i});
    }
    while(ord.size()){
        pii cur = *ord.rbegin();
        ord.erase(cur);
        //check left
        if((cur.nd - 1 >= 0) and abs(s[cur.nd] - s[cur.nd - 1]) > m){
            ord.erase({s[cur.nd - 1], cur.nd - 1});
            s[cur.nd - 1] += abs(s[cur.nd] - s[cur.nd - 1]) - m;
            ord.insert({s[cur.nd - 1], cur.nd - 1});
        }
        //check right
        if((cur.nd + 1 < n) and abs(s[cur.nd] - s[cur.nd + 1]) > m){
            ord.erase({s[cur.nd + 1], cur.nd + 1});
            s[cur.nd + 1] += abs(s[cur.nd] - s[cur.nd + 1]) - m;
            ord.insert({s[cur.nd + 1], cur.nd + 1});
        }
    }
    for(int i = 0; i < n; i++) cout << s[i] << " ";
    cout << "\n";
    return 0;
}