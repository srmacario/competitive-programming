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
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string s, p;
    set<char> ans;
    getline(cin, p);
    getline(cin, s);
    int j = 0;
    for(int i = 0; i < p.size() and j < s.size(); i++, j++){
        while(j < s.size() and p[i] != s[j]){
            ans.insert(s[j]);
            j++;
        }
    }
    while(j < s.size()){
        ans.insert(s[j]);
        j++;
    }
    for(auto c : ans) cout << c;
    cout << "\n";
    return 0;
}