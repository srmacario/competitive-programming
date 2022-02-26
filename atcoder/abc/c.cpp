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
const int N = 1e3+5;

int n;
string grid[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    //row
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n - 6; j++){
            int sum = 0;
            for(int k = j; k < j + 6; k++){
                if(grid[i][k] == '#') sum++;
            }
            if(sum >= 4){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    //column
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n - 6; j++){
            int sum = 0;
            for(int k = j; k < j + 6; k++){
                if(grid[k][i] == '#') sum++;
            }
            if(sum >= 4){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    //diagonal forward
    for(int i = 0; i <= n - 6; i++){
        for(int j = 0; j <= n - 6; j++){
            int sum = 0;
            for(int k = 0; k < 6; k++){
                if(grid[i + k][j + k] == '#') sum++;
            }
            if(sum >= 4){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    //diagonal backward
    for(int i = 0; i <= n - 6; i++){
        for(int j = 5; j < n; j++){
            int sum = 0;
            for(int k = 0; k < 6; k++){
                if(grid[i + k][j - k] == '#') sum++;
            }
            if(sum >= 4){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}