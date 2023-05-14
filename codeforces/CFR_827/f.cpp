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
        int q;
        cin >> q;
        ll cnt[3][26] = {0};
        char max_char[3] = {'a', 'a', 'a'}, min_char[3] = {'a', 'a', 'a'};
        for(int i = 1; i <= q; i++){
            int d, k;
            string x;
            cin >> d >> k >> x;
            for(auto ch : x) cnt[d][ch - 'a'] += k, max_char[d] = max(max_char[d], ch);
            if(min_char[1] != max_char[2]){
                cout << "YES\n";
            }
            else{
                if(max_char[1] == 'a' and cnt[1][0] < cnt[2][0]){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}