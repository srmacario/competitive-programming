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
const int N = 2e5 + 5;

int n, v[N], row[10][10], col[10][10], my_block[10][10], bck[10][10], my_reg[10][10], reg_sum[40], reg_cnt[40], reg_cur[40], reg_val[40][10];
int grid[10][10];

int block_def(int i, int j){
    int ans = 0;
    if(i >= 2) ans+=2;
    if(i >= 4) ans+=2;
    if(j >= 3) ans++;
    return ans;
}

bool check(int i, int j, int k){
    if(row[i][k]) return false;
    if(col[j][k]) return false;
    if(bck[my_block[i][j]][k]) return false;
    if(reg_val[my_reg[i][j]][k]) return false;
    if(reg_sum[my_reg[i][j]] + k > v[my_reg[i][j]]) return false;
    return true;
}

void add(int i, int j, int k){
    grid[i][j] = k;
    row[i][k] = 1;
    col[j][k] = 1;
    bck[my_block[i][j]][k] = 1;
    reg_sum[my_reg[i][j]] += k;
    reg_cur[my_reg[i][j]]++;
    reg_val[my_reg[i][j]][k] = 1;
}

void rem(int i, int j, int k){
    grid[i][j] = 0;
    row[i][k] = 0;
    col[j][k] = 0;
    bck[my_block[i][j]][k] = 0;
    reg_sum[my_reg[i][j]] -= k;
    reg_cur[my_reg[i][j]]--;
    reg_val[my_reg[i][j]][k] = 0;
}

int cnt;

bool bt(int i, int j){
    if(i == 6){
        for(int r = 0; r < 6; r++){
            for(int c = 0; c < 6; c++){
                cout << grid[r][c] << " ";
            }
            cout << "\n";
        }
        // db(cnt++);
        return true;
    }
    if(j == 6) return bt(i + 1, 0);
    for(int k = 1; k <= 6; k++){
        if(check(i, j, k)){
            add(i, j, k);
            bool ok = false;
            if(!(reg_cnt[my_reg[i][j]] == reg_cur[my_reg[i][j]] and reg_sum[my_reg[i][j]] != v[my_reg[i][j]])){
                ok = bt(i, j + 1);
            }
            rem(i, j, k);
            if(ok) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            int r;
            cin >> r;
            my_reg[i][j] = r;
            reg_cnt[r]++;
            my_block[i][j] = block_def(i, j);
        }
    }
    bt(0, 0);
    return 0;
}