#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n;
    cin >> n;
    cin >> s;
    int cnt = 0, tot = 0;
    for(int i = 0; i < s.size(); i++){
        if(!i){
            if(s[i] == 'a') cnt++;
            continue;
        }
        if(s[i] == 'a') cnt++;
        else{
            if(cnt > 1) tot += cnt;
            cnt = 0;
        }
    }
    if(cnt > 1) tot += cnt;
    cnt = 0;
    cout << tot << "\n";
    return 0;
}