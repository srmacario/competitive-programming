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
    int n, c;
    while(cin >> c >> n){
        if(!n and !c) return 0;
        vector<int> a(n + 1), mods(c);
        int l = -1, r = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i] = (a[i - 1] + a[i]) % c;
            if(a[i] == 0){
                l = 1, r = i;
            }
            else{
                if(mods[a[i]]){
                    l = mods[a[i]] + 1, r = i;
                }
                else mods[a[i]] = i;
            }
        }
        for(int i = l; i <= r; i++) cout << i << " ";
        cout << "\n";
    }
    return 0;
}