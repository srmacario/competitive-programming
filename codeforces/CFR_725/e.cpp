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
const int N = 55;

map<string, string> l_idx, r_idx;
map<string, ll> val;

int cmp(string &x){
    int ans = 0;
    for(int l = 0; l <= (int)x.size() - 4; l++){
        string cur = x.substr(l, 4);
        ans += (cur == "haha");
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt_string = 0;
        string last;
        for(int i = 0; i < n; i++){
            string lhs, op;
            cin >> lhs;
            cin >> op;
            if(op == ":="){
                string a;
                cin >> a;
                val[lhs] = cmp(a);
                string l_tmp, r_tmp;
                for(int j = 0; j < min(3, (int)a.size()); j++){
                    l_tmp += a[j];
                }
                for(int j = max((int)a.size()-3, 0); j < (int)a.size(); j++){
                    r_tmp += a[j];
                }
                l_idx[lhs] = l_tmp;
                r_idx[lhs] = r_tmp;
                // db("rd" _ l_idx[lhs] _ r_idx[lhs] _ val[lhs]);
            }
            else{
                string a, b, x, sa, sb;
                cin >> a >> x >> b;
                string tmp = r_idx[a] + l_idx[b];
                val[lhs] = val[a] + val[b] + cmp(tmp);
                sa = l_idx[a] + l_idx[b];
                sb = r_idx[a] + r_idx[b];
                string l_tmp, r_tmp;
                for(int j = 0; j < min(3, (int)sa.size()); j++){
                    l_tmp += sa[j];
                }
                for(int j = max((int)sb.size()-3, 0); j < (int)sb.size(); j++){
                    r_tmp += sb[j];
                }
                l_idx[lhs] = l_tmp;
                r_idx[lhs] = r_tmp;
                // db("add" _ l_idx[lhs] _ r_idx[lhs] _ val[lhs]);
            }
            last = lhs;
        }
        cout << val[last] << "\n";
        l_idx.clear();
        r_idx.clear();
        val.clear();
    }
    return 0;
}