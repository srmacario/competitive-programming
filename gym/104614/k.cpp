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

map<int, int> par[2], depth[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string c[2]; 
    for(int i = 0; i < 2; i++)
        getline(cin, c[i]);
    
    for(int i = 0; i < 2; i++){
        string s;
        int d = 0;
        s += "0(";
        for(auto ch : c[i]) if(ch != ' ') s += ch;
        s += ')';
        c[i] = s;
        string cur;
        stack<int> t;
        for(auto ch : c[i]){
            if(ch <= '9' and ch >= '0'){
                cur += ch;
            }
            else{
                if(cur.size()){
                    int num = stoi(cur);
                    cur.clear();
                    t.push(num);
                }
                if(ch == ')'){
                    int cur_num = t.top();
                    t.pop();
                    par[i][cur_num] = t.top();
                    depth[i][cur_num] = d;
                    d--;
                }
                else d++;
            }
        }
    }
    cout << ((par[0] == par[1] and depth[0] == depth[1]) ? "Yes\n" : "No\n");
    return 0;
}