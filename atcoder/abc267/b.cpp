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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if(s[0] == '1'){
        cout << "No\n";
        return 0;
    }
    set<int> columns[7];
    columns[0].insert(s[6] - '0');

    columns[1].insert(s[3] - '0');

    columns[2].insert(s[1] - '0');
    columns[2].insert(s[7] - '0');

    columns[3].insert(s[4] - '0');
    columns[3].insert(s[0] - '0');

    columns[4].insert(s[8] - '0');
    columns[4].insert(s[2] - '0');

    columns[5].insert(s[5] - '0');

    columns[6].insert(s[9] - '0');

    bool ok = false;
    for(int i = 0; i < 7; i++){
        for(int j = i + 1; j < 7; j++){
            if(!columns[i].count(1) or !columns[j].count(1)) continue;
            for(int k = i + 1; k < j; k++){
                if(columns[k].size() == 1 and columns[k].count(0)) ok = true;
            }
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}