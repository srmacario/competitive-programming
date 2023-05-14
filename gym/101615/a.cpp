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

string s;

bool is_pal(int l, int r){
    bool ok = true;
    for(int i=0;i<=(r-l)/2;i++){
        if(s[l+i] != s[r-i]) ok = false; 
    }
    return ok;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    bool odd = true;
    for(int l=0;l<s.size();l++){
        for(int r=l+1;r<s.size();r+=2){
            if(is_pal(l,r)) odd = false;
        }
    }
    cout << (odd ? "Odd.\n" : "Or not.\n");
    return 0;
}