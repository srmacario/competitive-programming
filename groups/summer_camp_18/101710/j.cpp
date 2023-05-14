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

string s;
int n;

vi pre(string s){
    vi pi(s.size());
    for(int i=1;i<s.size();i++){
        int j = pi[i-1];
        while(j > 0 and s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> s){
        n = s.size();
        vi pi = pre(s);
        int resp = n;
        cout << s.substr(0,(n-pi[n-1])) << "\n";
    }
    return 0;
}