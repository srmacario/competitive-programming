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
    ll q;
    cin >> q;
    while(q--){
        ll n, flip = -1, equal = 1;
        vector <ll> t;
        cin >> n;
        for(ll i=0;i<n;i++){
            ll x;
            cin >> x;
            if(i){
                if(x == t[i-1]) flip = i;
                else equal = 0;
            }
            t.pb(x);
        }
        if(equal){
            cout << "1\n";
            for(ll i =0;i<n;i++) cout << "1 ";
            cout << "\n";
        }
        else{
            if(n%2){
                if(t[0] == t[n-1]){
                    cout << "2\n";
                    for(ll i = 0;i<n;i++){
                        if(i%2) cout << "2 ";
                        else cout << "1 ";
                    }
                    cout << "\n"; 
                }
                else{
                    if(flip == -1){
                        cout << "3\n";
                        for(ll i = 0;i<n-1;i++){
                            if(i%2) cout << "2 ";
                            else cout << "1 ";
                        }
                        cout << "3 \n";  
                    }
                    else{
                        cout << "2\n";
                        for(ll i = 0;i<flip;i++){
                            if(i%2) cout << "2 ";
                            else cout << "1 ";
                        }
                        for(ll i = flip;i<n;i++){
                            if(i%2) cout << "1 ";
                            else cout << "2 ";
                        }
                        cout << "\n"; 
                    }
                }
            }
            else{
                cout << "2\n";
                for(ll i = 0;i<n;i++){
                    if(i%2) cout << "2 ";
                    else cout << "1 ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}