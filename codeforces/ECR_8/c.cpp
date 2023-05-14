#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
    int n,k,dmax = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        dmax += max((abs('z'-s[i])),(abs('a'-s[i])));
    }
    if(k > dmax) cout << "-1\n";
    else{
        for(int i=0;i<n;i++){
            char d;
            if(!k){
                cout << s[i];
                continue;
            }
            if( (abs('z'-s[i])) > (abs('a'-s[i])) ) d = 'z';
            else d = 'a';
            if(k >= abs(d-s[i])){
                k -= abs(d-s[i]);
                cout << d;
            } 
            else{
                char c;
                if(d == 'a') c = s[i] - k;
                else c = s[i] + k;
                cout << c;
                k = 0;
            }
        }
        cout << "\n";
    }
    return 0;
}