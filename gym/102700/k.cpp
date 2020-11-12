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
    string a,b;
    cin >> a >> b;
    int up = min(a.size(),b.size());
    string stra, strb, numa, numb;
    bool numok = false;
    for(int i=0;i<a.size();i++){
        if(a[i] - '0' < 10) numok = true;
        if(numok) numa += a[i];
        else stra += a[i];
    }
    numok = false;
    for(int i=0;i<b.size();i++){
        if(b[i] - '0' < 10) numok = true;
        if(numok) numb += b[i];
        else strb += b[i];
    }
    if(stra == strb){
        if(numa.size() == numb.size()){
            if(numa > numb) cout << ">";
            else if(numa < numb) cout << "<";
            else cout << "=";
        }
        else{
            if(numa.size() > numb.size()) cout << ">";
            else cout << "<";
        }
    }
    else{
        if(a > b) cout << ">";
        else cout << "<";
    }
    cout << "\n";
    return 0;
}