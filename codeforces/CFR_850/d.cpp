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

map<char, map<char, vector<int>>> need;
map<char, bool> changed;
vector<pair<pair<int, char>, pair<int, char>>> ans;


void check_need(string s, int i){
    set<char> want;
    vector<char> have;
    want.insert('w'), want.insert('i'), want.insert('n');
    for(auto ch : s){
        if(want.count(ch)){
            want.erase(ch);
        }
        else{
            have.push_back(ch);
        }
    }
    for(auto ch : have){
        char wanted = *want.begin();
        need[ch][wanted].push_back(i);
        want.erase(want.begin());
    }
}

void do_change(char a, char b, char c){
        //try a -> b direct exchange
        while(need[a][b].size() and need[b][a].size()){
            //cout << need[a][b].back() << " " << a << " " << need[b][a].back() << " " << b << "\n";
            ans.push_back({{need[a][b].back(), a}, {need[b][a].back(), b}});
            need[b][a].pop_back();
            need[a][b].pop_back();
        }
        //case a needs more b, change a for the b's who want c
        while(need[a][b].size()){
            //cout << need[a][b].back() << " " << a << " " << need[b][c].back() << " " << b << "\n";
            ans.push_back({{need[a][b].back(), a}, {need[b][c].back(), b}});
            need[b][a].push_back(need[b][c].back());
            need[b][c].pop_back();
            need[a][b].pop_back();
            changed[b] = true;
        }
}

void fix_change(char a, char b, char c){
    //a -> b direct exchange
    while(need[a][b].size() and need[b][a].size()){
        //cout << need[a][b].back() << " " << a << " " << need[b][a].back() << " " << b << "\n";
        ans.push_back({{need[a][b].back(), a}, {need[b][a].back(), b}});
        need[b][a].pop_back();
        need[a][b].pop_back();
    }
    //a -> c should be matched with b -> c
    while(need[a][c].size()){
        ans.push_back({{need[a][c].back(), (changed[a] ? c : a)}, {need[b][c].back(), (changed[b] ? c : b)}});
        //cout << need[a][c].back() << " " << (changed[a] ? c : a) << " " << need[b][c].back() << " " << (changed[b] ? c : b) << "\n";
        need[b][c].pop_back();
        need[a][c].pop_back();
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        changed.clear();
        need.clear();
        ans.clear();
        int m;
        cin >> m;
        vector<string> p(m + 1);
        for(int i = 1; i <= m; i++){
            cin >> p[i];
            check_need(p[i], i);
        }
        do_change('w', 'i', 'n');
        do_change('w', 'n', 'i');
        fix_change('i', 'n', 'w');
        cout << ans.size() << "\n";
        for(auto r : ans){
            cout << r.st.st << " " << r.st.nd << " " << r.nd.st << " " << r.nd.nd << "\n";
        }
    }
    return 0;
}