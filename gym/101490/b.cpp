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
    string s,cur;
    cin >> s;
    for(int i=0;i<s.size();i++){
        int rcnt = 0, bcnt = 0, lcnt = 0;
        for(int j=0;j<3;j++){
            if(s[i+j] == 'R') rcnt++;
            if(s[i+j] == 'B') bcnt++;
            if(s[i+j] == 'L') lcnt++;
        }
        if(rcnt and bcnt and lcnt) cur += "C", i+=2;
        else{
            if(s[i] == 'R') cur += "S";
            if(s[i] == 'B') cur += "K";
            if(s[i] == 'L') cur += "H";
        }
    }
    cout << cur << "\n";
    return 0;
}