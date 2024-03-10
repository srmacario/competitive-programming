#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define endl '\n'

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
    int n;
    cin >> n;
    vector<string> a(n); 
    vector<int> cnt0, cnt1;      
    vector<int> ans(4, 1e9);
    ans[0] = 0;
    int h1 = false, h2 = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int c0 = 0, c1 = 0;
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] == '0') c0++;
            else c1++;
        }
        if(c0) h1 = 1;
        if(c1) h2 = 1;
        vector<int> nans(4);
        for(int j = 0; j < 4; j++) {
            nans[j] = ans[j] + min(c0, c1);
        }
        nans[3] = min(nans[3], ans[1] + c1);
        nans[3] = min(nans[3], ans[2] + c0);
        nans[1] = min(nans[1], ans[0] + c0);
        nans[2] = min(nans[2], ans[0] + c1);
        ans = nans;
    }
    if(!h1 or !h2) {
        cout << 0 << endl;
    } else {
        cout << ans[3] << endl;

    }


    return 0;
}