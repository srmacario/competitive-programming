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
    string s[10];
    int a = -1, b = -1, c = 0, d = 0;
    for(int i = 0; i < 10; i++){
        cin >> s[i];
        int ini = -1, fim = -1;
        for(int j = 0; j < s[i].size(); j++){
            if(ini == -1 and s[i][j] == '#') ini = j;
            if(s[i][j] == '#') fim = j;
        }
        if(ini != -1 and fim != -1){
            c = ini, d = fim;
            if(a == -1) a = i;
            b = i;
        }
    }
    cout << (a + 1) << " " << (b + 1) << "\n";
    cout << (c + 1) << " " << (d + 1) << "\n";
    return 0;
}