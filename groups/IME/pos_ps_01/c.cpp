#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define dbs(x) cerr << x << endl;
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 105;

int grid[N][N], n, k, l;
ll ans = 0;

void move_down(){
    for(int j = 0; j < n; j++){
        int pos = n - 1, last = 0;
        for(int i = n - 1; i >= 0; i--){
            int val = grid[i][j];
            grid[i][j] = 0;
            if(!val) continue;
            if(val == last){
                grid[pos + 1][j] = 2 * last;
                ans += 2ll * last;
                last = 0;
            }   
            else{
                grid[pos][j] = val;
                last = val;
                pos--;
            } 
        }
    }
}

void move_up(){
    for(int j = 0; j < n; j++){
        int pos = 0, last = 0;
        for(int i = 0; i < n; i++){
            int val = grid[i][j];
            grid[i][j] = 0;
            if(!val) continue;
            if(val == last){
                grid[pos - 1][j] = 2 * last;
                ans += 2ll * last;
                last = 0;
            }   
            else{
                grid[pos][j] = val;
                last = val;
                pos++;
            }
        }
    }
}

void move_left(){
    for(int i = 0; i < n; i++){
        int pos = 0, last = 0;
        for(int j = 0; j < n; j++){
            int val = grid[i][j];
            grid[i][j] = 0;
            if(!val) continue;
            if(val == last){
                grid[i][pos - 1] = 2 * last;
                ans += 2ll * last;
                last = 0;
            }   
            else{
                grid[i][pos] = val;
                last = val;
                pos++;
            }
        }
    }
}

void move_right(){
    for(int i = 0; i < n; i++){
        int pos = n - 1, last = 0;
        for(int j = n - 1; j >= 0; j--){
            int val = grid[i][j];
            grid[i][j] = 0;
            if(!val) continue;
            if(val == last){
                grid[i][pos + 1] = 2 * last;
                ans += 2ll * last;
                last = 0;
            }   
            else{
                grid[i][pos] = val;
                last = val;
                pos--;
            }
        }
    }
}

ll sum(){
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
            ans += grid[i][j];
        }
        cout << "\n";
    }
    return ans;
}

void move(char dir){
    if(dir == 'U') move_up();
    if(dir == 'D') move_down();
    if(dir == 'L') move_left();
    if(dir == 'R') move_right();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int v, x, y;
        cin >> v >> x >> y;
        grid[x - 1][y - 1] = v;
    }
    //sum();
    // cout << "\n";
    cin >> l;
    for(int i = 0; i < l; i++){
        char dir;
        int v, x, y;
        cin >> dir >> v >> x >> y;
        move(dir);
        grid[x - 1][y - 1] = v;
        //sum();
        // cout << "\n";
    }
    //cout << sum() << "\n";
    cout << ans << "\n";
    return 0;
}