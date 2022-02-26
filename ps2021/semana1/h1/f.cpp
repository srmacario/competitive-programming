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

map<string, int> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = (int)s.size();
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            m[s.substr(l, r-l+1)]++;
        }
    }
    int cnt = 0;
    cnt += m["Danil"];
    cnt += m["Olya"];
    cnt += m["Slava"];
    cnt += m["Ann"];
    cnt += m["Nikita"];
    if(cnt == 1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}