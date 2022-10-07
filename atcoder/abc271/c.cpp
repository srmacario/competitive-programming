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
const int N = 3e5+5;

int n, a[N];
vector<int> vols;
map<int, int> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int extra = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(!m.count(a[i])){
            m[a[i]] = 1;
            vols.push_back(a[i]);
        }
        else{
            extra++;
        }
    }
    sort(vols.begin(), vols.end());
    int last, l, r;
    for(last = 1, l = 0, r = vols.size() - 1;(l <= r); last++){
        if(vols[l] == last){
            l++;
            continue;
        }
        if(extra >= 2){
            extra -= 2;
            continue;
        }
        if(extra == 1){
            r--;
            extra--;
            continue;
        }
        if(l <= r - 1){
            r -= 2;
            continue;
        }
        break;
    }
    last +=  (max(0, (r - l + 1)) + extra) / 2;
    cout << last - 1 << "\n";
    return 0;
}