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

int top[2][9], bot[5][9];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, cnt = 0, dig[9] = {0};
        cin >> n;
        for(int i=0;i<9;i++){
            top[0][i] = bot[1][i] = bot[2][i] = bot[3][i] = bot[4][i] = 1;
            top[1][i] = bot[0][i] = 0;
        }
        while(n){
            dig[cnt] = n%10;
            n/=10;
            cnt++;
        }
        for(int i=0;i<9;i++){
            if(dig[i]>=5){
                swap(top[0][i],top[1][i]);
                dig[i]-=5;
            }
            swap(bot[0][i],bot[dig[i]][i]);
        }
        for(int j=0;j<=1;j++){
            for(int i=8;i>=0;i--){
                cout << top[j][i];
            }
            cout << "\n";
        }
        for(int i=0;i<9;i++) cout << "-";
        cout << "\n";
        for(int j=0;j<=4;j++){
            for(int i=8;i>=0;i--){
                cout << bot[j][i];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}