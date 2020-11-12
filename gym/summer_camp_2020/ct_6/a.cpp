#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
pii dmin;
struct settle{
    int d = 0 ,r = 0,t = 0,h = 0;
};

vector<settle> lis;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    dmin.st = INF;
    for(int i=0;i<n;i++){
        settle x;
        cin >> x.h >> x.r >> x.t;
        lis.pb(x);
        if(dmin.st > x.h) dmin.st = x.h, dmin.nd = i;
    }
    int cnt= 0;
    for(int i=1;i<=1825;i++){
        bool ok = true;
        for(int j=0;j<dmin.st;j++){
            cout << j << " ";
            for(int k=0;k<lis.size();k++){
                cout << lis[k].r%lis[k].h << " ";
                if(cnt%lis[k].h > lis[k].r%lis[k].h or cnt%lis[k].h < lis[k].t%lis[k].h) ok = false;            
            }   
        if(ok){
            cout << cnt << "\n";
            return 0;
        }
        cnt++;
        cout << "\n";
        }
    }
    cout << "impossible\n";
    return 0;
}