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
const int N = 1e6 + 50, R = 26;

int dfa[R][N];
int q, X, ini_X, S, T;
string s, t;

void calc_dfa(){
    dfa[s[0] - 'a'][0] = 1;
    S = s.size();
    for(int j = 1; j < S; j++){
        for(int c = 0; c < R; c++)
            dfa[c][j] = dfa[c][X];
        dfa[s[j] - 'a'][j] = j + 1;
        X = dfa[s[j] - 'a'][X];
    }
    ini_X = X;
}

void inc_dfa(){
    T = t.size();
    X = ini_X;
    for(int j = 0; j < T; j++){
        for(int c = 0; c < R; c++)
            dfa[c][S + j] = dfa[c][X];
        dfa[t[j] - 'a'][S + j] = S + j + 1;
        X = dfa[t[j] - 'a'][X];
        cout << X << " ";
    }
    cout << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> q;
    calc_dfa();
    for(int k = 0; k < q; k++){
        cin >> t;
        inc_dfa();
    }
    return 0;
}