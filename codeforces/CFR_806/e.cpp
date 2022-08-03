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
        int n;
        cin >> n;
        int ans = 0;
        vector<string> grid(n);
        for(int i = 0; i < n; i++){
            cin >> grid[i];
        }
        for(int i = 0; i < (n + 1)/2; i++){
            for(int j = 0; j < n / 2; j++){
                int cnt[2] = {0};
                int cur_i = i, cur_j = j;
                do{
                    int tmp_i = cur_i;
                    cur_i = cur_j;
                    cur_j = n - tmp_i - 1;
                    cnt[grid[cur_i][cur_j] - '0']++;
                }while((i != cur_i) or (j != cur_j));
                ans += min(cnt[0], cnt[1]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
    (0, 0) -> (0, 3)
    (1, 0) -> (0, 2) -> (2, 3) -> (3, 1)
    (2, 0) -> (0, 1) -> (1, 3) -> (3, 2)
    (1, 1) -> (1, 2) -> (2, 2) -> (2, 1)
    (i, j) -> (j, n - i - 1)

    0 1 2 3 4
    4 5 6 7 4
    0 1 2 3 4
    0 1 2 3 4
    0 1 2 3 4
*/