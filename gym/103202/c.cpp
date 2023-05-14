#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, m, q[2][N];
bool ok = true, notv[N], val[N];
vector<pii> adj[N];
vector<int> is_false, is_true;
vector<pair<vector<int>, int>> is_false_cond, is_true_cond; 

pair<bool, pair<string, string>> split(string& s) {
    string bef, aft;
    bool appear = false;
    
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '-') {
            i += 2;
            appear = true;
        } else if (appear) {
            aft += s[i];
        } else {
            bef += s[i];
        }
    }

    return { appear, { bef, aft }};
}

pair<bool, int> parse_simple(string& s) {
    bool is_true = true;
    int i = 0;
    if (s[0] == '!') {
        i++;
        is_true = false;
    }

    int num = 0;
    for(; i < (int)s.size(); i++) {
        if (!isdigit(s[i])) assert(false);
        num = 10 * num + (s[i] - '0');
    }

    return { is_true, num };
}

vector<int> parse_multiple(string& s) {
    int num = 0;
    vector<int> ans;
    for (int i = 0; i < (int)s.size(); i++) {
        if (isdigit(s[i])) {
            num = 10 * num + (s[i] - '0');
        } else {
            ans.push_back(num);
            num = 0;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string line;
    getline(cin, line);

    while(n--) {
        getline(cin, line);
        auto inp = split(line);
        if (inp.first) {
            vector<int> cond = parse_multiple(inp.second.first);
            auto res = parse_simple(inp.second.second);

            if (res.first) {
                is_true_cond.push_back({ cond, res.second });
            } else {
                is_false_cond.push_back({ cond, res.second });
            }
        } else {
            auto res = parse_simple(inp.second.first);

            if (res.first) {
                is_true.push_back(res.second);
            } else {
                is_false.push_back(res.second);
            }
        }
    }

            //  cout << "is_true\n";
            //  for (auto x : is_true)
            //      cout << x << " ";
            //  cout << "\n";

            //  cout << "is_false\n";
            //  for (auto x : is_false)
            //      cout << x << " ";
            //  cout << "\n";

            //  cout << "is_true_cond\n";
            //  for (auto x : is_true_cond) {
            //      cout << "cond\n";
            //      for (auto y : x.first) cout << y << " ";
            //      cout << "\n";
            //      cout << x.second;
            //      cout << "\n";
            //  }
            //  cout << "\n";

            //  cout << "is_false_cond\n";
            //  for (auto x : is_false_cond) {
            //      cout << "cond\n";
            //      for (auto y : x.first) cout << y << " ";
            //      cout << "\n";
            //      cout << x.second;
            //      cout << "\n";
            //  }
            //  cout << "\n";
    for(int i = 0; i < is_false_cond.size(); i++){
        q[0][i] = is_false_cond[i].st.size();
        for(int j : is_false_cond[i].st)
            adj[j].push_back({0, i});
    }
    for(int i = 0; i < is_true_cond.size(); i++){
        q[1][i] = is_true_cond[i].st.size();
        for(int j : is_true_cond[i].st)
            adj[j].push_back({1, i});
    }
    for(int i : is_false)
        notv[i] = true;
    for(int j = 0; j < is_true.size(); j++){
        int i = is_true[j];
        if(val[i])
            continue;
        val[i] = true;
        for(pii k : adj[i]){
            q[k.st][k.nd]--;
            if(q[k.st][k.nd] == 0){
                if(k.st == 0)
                    notv[is_false_cond[k.nd].nd] = true;
                else if(!val[is_true_cond[k.nd].nd])
                    is_true.push_back(is_true_cond[k.nd].nd);
            }
        }
    }
    for(int i = 1; i <= m; i++)
        if(val[i] && notv[i])
            ok = false;
    if(ok){
        for(int i = 1; i <= m; i++){
            if(val[i] == 1)
                cout << "T";
            else
                cout << "F";
        }
        cout << '\n';
    }
    else
        cout << "conflict\n";
    return 0;
}