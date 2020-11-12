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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        if(n < k){
            cout << "NO\n";
            continue;
        }
        if(n%2){
            if(!(k%2)) cout << "NO\n";
            else{
                cout << "YES\n";
                for(int i=0;i<k-1;i++) cout << "1 ";
                cout << n - k + 1 << "\n";
            }
        }
        else{
            if((k%2)){
                if(!((n - 2*k)%2) and n - 2*k >= 0){
                    cout << "YES\n";
                    for(int i=0;i<k-1;i++) cout << "2 ";
                    cout << n - 2*(k - 1) << "\n";
                }
                else cout << "NO\n";
            }
            else{
                cout << "YES\n";
                for(int i=0;i<k-1;i++) cout << "1 ";
                cout << n - k + 1 << "\n";
            }
        }
    }
    return 0;
}