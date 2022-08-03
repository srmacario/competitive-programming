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

bool check_pal(string s, int n){
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    for(int i = 2; i < n; i += 2){
        for(int j = 0; j <= n - i; j++){
            if(check_pal(s.substr(j, i), i)) ok = false;
        }
    }
    cout << (ok ? "Odd.\n" : "Or not.\n");
    return 0;
}