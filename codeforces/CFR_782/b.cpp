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
    int t;
    cin >> t;
    while(t--){
        int n, k, cnt = 0;
        string s;
        cin >> n >> k >> s;
        int look  = (k % 2);
        vector<int> pos;
        for(int i = 0; i < n - 1; i++){
            if(s[i] - '0' == look) pos.push_back(i);
            if(look == 1) s[i] = (((s[i] - '0') ^ 1) + '0');
        }
        vector<int> ans(n);
        for(int i = 0; i < pos.size() and k; i++, k--){
            s[pos[i]] = '1';
            ans[pos[i]]++;
            cnt++;
        }
        ans.back() = k;
        if(s.back() == '1'){
            if(cnt % 2) s.back() = '0';
        }
        else if(s.back() == '0'){
            if(cnt % 2) s.back() = '1';
        }
        cout << s << "\n";
        for(auto a : ans) cout << a << " ";
        cout << "\n";
    }
    return 0;
}