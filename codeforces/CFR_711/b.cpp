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

int box[60];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        memset(box, 0, sizeof(box));
        int n, w;
        cin >> n >> w;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            for(int j = 0; j <= 30; j++){
                if(1<<j == x){
                    box[j]++;
                    break;
                }
            }
        }
        int ans = 0;
        while(n){
            ++ans;
            int cur = w;
            for(int j = 30; j >= 0; j--){
                int pot = 1<<j;
                if((pot & cur)){
                    for(int k = j; k >= 0; k--){
                        while(box[k] and pot){
                            box[k]--, pot -= 1<<k, n--;
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}