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
    int n, dif = 0, i = 0;
    string s;
    cin >> n >> s;
    for(; i < s.size(); i++){
        int val = 1;
        if(s[i] == 'M') val = -1;
        if(abs(dif + val) > n){
            if(i + 1 == s.size()) break;
            if(s[i + 1] != s[i]){
                swap(s[i], s[i + 1]);
                dif += -1 * val;
            }
            else break;
        }        
        else dif += val;
    }
    cout << i << "\n";
    return 0;
}