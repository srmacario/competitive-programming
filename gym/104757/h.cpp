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
    int n;
    cin >> n;
    __uint128_t mult = 2, ten = 10;
    vector<__uint128_t> val(n);
    for(int i = 0; i < n; i++){
        __uint128_t cur = 0, pot = 1, mul = 10;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++){
            __uint128_t ch_val = (s[i] - '0');
            cur = (cur +  ch_val * pot);
            pot = (pot * mul);
        }
        val[i] = cur;
    }

    bool ok = true;
    __uint128_t ans = 0;
    while(ok){
        int n = val.size();
        vector<__uint128_t> tmp;
        ok = false;
        for(int i = 0; i < n; i++){
            if(i != n - 1 and val[i] == val[i + 1]){
                tmp.push_back(val[i] + val[i]);
                i++;
                ok = true;
            }
            else tmp.push_back(val[i]);
        }
        val = tmp;
        db(ok _ val.size());
    }

    for(int i = 0; i < val.size(); i++) ans = max(ans, val[i]);
    
    string sans;
    while(ans){
        sans += static_cast<int>((ans % ten)) + '0';
        ans /= ten;
    }
    reverse(sans.begin(), sans.end());
    cout << sans << "\n";
    return 0;
}