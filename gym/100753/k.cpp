#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector <int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+1;

ll x, y, n, pot[20];
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n = s.size();
    pot[0] = 1;
    for(ll i=1;i<20;i++) pot[i] = 10*pot[i-1];
    for(ll i=0;i<n;i++){
        if(s[i] == '7' or s[i] == '3' or s[i] == '4'){
            cout << "no\n";
            return 0;
        }
        y += (s[i] - '0') * pot[n-1-i];
        if(s[i] == '6') s[i] = '9';
        else if(s[i] == '9') s[i] = '6';
        x += (s[i] - '0') * pot[i];
    }
    if(x == 1 or y == 1){
        cout << "no\n";
        return 0;
    }
    for(ll i=2; i*i <= x;i++){
        if(!(x % i) or !(y % i)){
            cout << "no\n";
            return 0;
        }
    }
    cout <<"yes\n";
    return 0;
}
