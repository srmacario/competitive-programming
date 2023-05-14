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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    set<char> box;
    bool faint = false;
    vector<int> l, letter;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            l.push_back(i);
        }
        else if(s[i] == ')'){
            while(letter.size() and letter.back() >= l.back()){
                box.erase(s[letter.back()]);
                letter.pop_back();
            }
            l.pop_back();
        }
        else{
            if(box.count(s[i])){
                faint = true;
                break;
            }
            else{
                box.insert(s[i]);
            }
            letter.push_back(i);
        }
    }
    if(faint) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}