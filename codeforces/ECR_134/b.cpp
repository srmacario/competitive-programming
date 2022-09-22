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
        int n, m, d;
        pii cant;
        cin >> n >> m >> cant.st >> cant.nd >> d;
        int ans = (n + m - 2);
        bool ok = false;
        for(int j = 1; j <= m; j++){
            if((abs(cant.nd - j) > d)){
                if(j > cant.nd){
                    if(abs(cant.st - 1) > d){
                        cout << ans << "\n";
                        ok = true;
                        break;
                    }
                }
                else{
                    if(abs(cant.st - n) > d){
                        cout << ans << "\n";
                        ok = true;
                        break;
                    }
                }
            }
        }
        if(!ok) cout << "-1\n";
    }
    return 0;
}
/*
    . * *
    . . * 


*/