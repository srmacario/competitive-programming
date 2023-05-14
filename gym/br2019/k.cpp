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
typedef vector<ll> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e4+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vii pol;
    int roots = 0;
    for(int i = 1; i < (int)s.size(); i++){
        if(s[i] != s[i-1]){
            vi p(2);
            p[0] = 1;
            p[1] = -(2*i + 1);
            pol.pb(p);
            roots++;
        }
    }
    if(pol.empty()){
        cout << "0\n" << (s[0] == 'H' ? 1 : -1) << "\n";
    }
    else{
        vi ans = pol.back();
        pol.pop_back();
        while(!pol.empty()){
            vi tmp = ans;
            ans.push_back(0);
            for(int i = (int)tmp.size()-1; i >= 0; i--){
                ans[i+1] += pol.back()[1]*tmp[i];
            }
            pol.pop_back();
        }
        cout << roots << "\n";
        int sgn = 1;
        if(s[0] == 'A') sgn = -1;
        if(ans.back()*sgn < 0) sgn = -1;
        else sgn = 1; 
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i]*sgn;
            if(i < ans.size()-1) cout << " ";
        }
       cout << "\n";
    }
    return 0;
}