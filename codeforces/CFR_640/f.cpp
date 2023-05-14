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
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        /*if(n2 and !n1 and !n3){
            cout << "01";
        }*/
        if(!(n2%2) and n2){
            cout << "0";
            n2--;
        }
        if(n3){
            for(int i=1;(i<=n3+1);i++) cout << "1";
        }
        else if (n2){
            cout << "1";
        }
        for(int i=0;i<n2-2;i+=2) cout << "01";
        if(n1){
            for(int i=1;(i<=n1+1);i++) cout << "0";
        }
        else if(n2){
            cout << "0";
        }
        cout << "\n";
    }
    return 0;
}