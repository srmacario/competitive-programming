#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5 + 5;

string grid[3] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
string cur[3];
set<int> freq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 3; i++){
        cin >> cur[i];
        for(int j = 0; j < cur[i].size(); j++){
            if(cur[i][j] == '*') freq.insert(grid[i][j] - 'A');
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        bool ok = true;
        set<int> tmp_freq;
        for(int j = 0; j < s.size(); j++){
            tmp_freq.insert(s[j] - 'A');
        }
        ok = (freq == tmp_freq);
        cout << (ok ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }
    return 0;
}