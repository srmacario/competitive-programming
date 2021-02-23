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
    int t;
    cin >> t;
    while(t--){
        int n, s, old;
        char mid;
        cin >> n >> s;
        old = n;
        string l,r;
        if(s%2 and !(n%2)){
            cout << "-1\n";
            continue;
        }
        else{
            if(n*9 < s or (s == 1 and n > 1)){
                cout << "-1\n";
                continue;
            }
            if(s%2) mid = '1', s-=1, n-=1;
            else if(n%2) mid = '0';
            for(int i=0;i<n/2;i++){
                if(18 > s) r += s/2 + '0', l += s/2 + '0', s = 0;
                else{
                    s -= 18;
                    r += '9';
                    l += '9';
                }
            }
            mid += s;
            reverse(r.begin(),r.end());
            cout << l;
            if(old%2) cout << mid;
            cout << r << "\n";
        }
    }
    return 0;
}