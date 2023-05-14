#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

map<string, pii> s;

bool check(string g, char ch){
    if(g[0] == g[3] and g[0] == g[6] and g[0] == ch) return true;
    if(g[1] == g[4] and g[1] == g[7] and g[1] == ch) return true;
    if(g[2] == g[5] and g[2] == g[8] and g[2] == ch) return true;

    if(g[0] == g[1] and g[0] == g[2] and g[0] == ch) return true;
    if(g[3] == g[4] and g[3] == g[5] and g[3] == ch) return true;
    if(g[6] == g[7] and g[6] == g[8] and g[6] == ch) return true;

    if(g[0] == g[4] and g[0] == g[8] and g[0] == ch) return true;
    if(g[2] == g[4] and g[2] == g[6] and g[2] == ch) return true;
    return false;
}

pair<int, int> dfs(string g, int play){
    if(s.count(g)) return s[g];
    if(check(g, 'O')){
        //(g == "OOOX.X.X.") db(play _ g _ s[g].st _ s[g].nd);
        return s[g] = {1, 0};
    }
    if(check(g, 'X')){
        return s[g] = {0, 1};
    }
    if(g == "OOOX.X.X.") db(play _ g _ s[g].st _ s[g].nd);
    pii ans = {0, 0};
    for(int i = 0; i < g.size(); i++){
        if(g[i] == '.'){
            pii tmp = {0, 0};
            if(play == 0){
                g[i] = 'O';
                tmp = dfs(g, 1);
            }
            if(play == 1){
                g[i] = 'X';
                tmp = dfs(g, 0);
            }
            ans.st += tmp.st, ans.nd += tmp.nd;
            g[i] = '.';
        }
    }
    return s[g] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    dfs(".........", 1);
    while(t--){
        string g;
        cin >> g;
        if(s.count(g)) cout << s[g].nd << " " << s[g].st << "\n";
        else cout << "-1 -1\n";
    }
    return 0;
}

/*
XOX
XXX
XOO
*/