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
const int N = 105;

int n, m, h;
string mat[2][N];
bool max_ans[N][N][N], min_ans[N][N][N];
int max_cnt, min_cnt;

bool check(){
    for(int i = 0; i < n; i++){
        for(int k = 0; k < h; k++){
            if(mat[1][i][k] == '0') continue;
            bool ok = false;
            for(int j = 0; j < m; j++){
                if(mat[0][i][j] == '0') continue;
                ok = true;
            }
            if(!ok) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> h;
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < n; i++){
            cin >> mat[k][i];
        }
    }
    //find max
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[0][i][j] == '0') continue;
            bool ok = false;
            for(int k = 0; k < h; k++){
                if(mat[1][i][k] == '0') continue;
                max_ans[i][j][k] = 1;
                max_cnt++;
                ok = true;
            }
            if(!ok){
                cout << "-1\n";
                return 0;
            }
        }
    }
    if(!check()){
        cout << "-1\n";
        return 0;
    }
    cout << max_cnt << "\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < h; k++)
                if(max_ans[i][j][k])
                    cout << i << " " << j << " " << k << "\n";
    
    //find min
    for(int i = 0; i < n; i++){
        int cnt[2] = {0};
        for(int j = 0; j < m; j++) if(mat[0][i][j] == '1') cnt[0]++;
        for(int k = 0; k < h; k++) if(mat[1][i][k] == '1') cnt[1]++;
        int dif = abs(cnt[0] - cnt[1]);
        if(cnt[0] >= cnt[1]){
            int k = 0;
            while(mat[1][i][k] == '0') k++;
            for(int j = 0; j < m; j++){
                if(mat[0][i][j] == '0') continue;
                
                if(dif == 0){
                    while(mat[1][i][k] == '0') k++;
                    min_ans[i][j][k] = 1;
                    min_cnt++;
                    k++;
                }
                else{
                    min_ans[i][j][k] = 1;
                    min_cnt++;
                    dif--;
                }
            }
        }
        else{
            int j = 0;
            while(mat[0][i][j] == '0') j++;
            for(int k = 0; k < h; k++){
                if(mat[1][i][k] == '0') continue;
                
                if(dif == 0){
                    while(mat[0][i][j] == '0') j++;
                    min_ans[i][j][k] = 1;
                    min_cnt++;
                    j++;
                }
                else{
                    min_ans[i][j][k] = 1;
                    min_cnt++;
                    dif--;
                }
            }
        }
    }
    
    cout << min_cnt << "\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < h; k++)
                if(min_ans[i][j][k])
                    cout << i << " " << j << " " << k << "\n";
    return 0;
}