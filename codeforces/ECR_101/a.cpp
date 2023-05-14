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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        bool ok = true;
        string s;
        cin >> s;
        int op = 0, n = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' and !op) op = 1;
            if(s[i] == ')' and !op) op = -1;
            if(s[i] == '?') n++;
        }
        if(n%2) ok = false;
        if(op == -1 and (s[0] != '?' or s[s.size()-1] != '?')) ok = false;
        cout << (ok ? "YES" : "NO") << "\n"; 
    }
    return 0;
}