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
const int N = 2e5+5, M = 105;

int a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi num;
    int sum = 0;
    int pos = 0;
    a[0] = 1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
        num.pb(x);
    }
    for(auto x : num){
        for(int i = N-1; i >= 0; i--){
            if(a[i]) a[i+x]++;
        }
    }
    if(sum%2){
        cout << "0\n";
    }
    else{
        if(a[sum/2]){
            while(!pos){
                for(int i = 0; i < n; i++){
                    if(num[i]%2){
                        pos = i+1;
                        break;
                    }
                    num[i]/=2;
                }
            }
            cout << "1\n" << pos << endl;
        }
        else cout << "0\n";
    }
    return 0;
}