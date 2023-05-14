#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 1005;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi inii,fimi,inip,fimp;
        if(n < 4){
            cout << "-1\n";
            continue;
        }
        if(n == 4){
            cout << "3 1 4 2\n";
            continue;
        }
        int aux = 0;
        for(int i=3;i<=n;i+=2){
            if(aux) fimi.pb(i);
            else inii.pb(i);
            aux = aux^1;
        }
        aux = 0;
        for(int i=4;i<=n;i+=2){
            if(aux) fimp.pb(i);
            else inip.pb(i);
            aux = aux^1;
        }
        for(int i=0;i<fimp.size();i++) cout << fimp[i] << " ";
        for(int i=inip.size()-1;i>=0;i--) cout << inip[i] << " ";
        cout << "2 ";
        for(int i=0;i<fimi.size();i++) cout << fimi[i] << " ";
        for(int i=inii.size()-1;i>=0;i--) cout << inii[i] << " ";
        cout << "1\n";
    }
    return 0;
}