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

string s,p;
int pi[N],n,m;

void pre(){
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j > 0 and s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

void kmp(){
    for(int i=0, j=0;i<m;i++){
        while(j > 0 and p[i] != s[j])
            j = pi[j-1];
        if(p[i] == s[j]){
            j++;
            if(j == n) {
                db(i-j+1);
                j = p[j-1];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> p;
    n = s.size(), m = p.size();
    pre();
    for(int i=0;i<n;i++) cout << pi[i];
    kmp();
    return 0;
}