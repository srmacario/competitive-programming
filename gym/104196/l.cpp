#include <bits/stdc++.h>

#define st first
#define nd second

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
using namespace std;

typedef long long ll;

const int N = 100;

int n, m;
int grid[N][N];
int d[2][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] > -1) v.push_back(grid[i][j]);
        }
    }
    sort(v.begin(), v.end());
    map<int, int> where;
    vector<int> should;
    int ans = INT_MAX, pos = 0, tmp = 0;
    //d1
    for(int i = 0; i < n; i++){
        int diag = 0;
        for(int j = 0; j < m; j++){
            if(grid[i][j] > -1){
                pos = (lower_bound(v.begin(), v.end(), grid[i][j]) - v.begin());
                where[pos] = diag + i;
                should.push_back(diag + i);
            }
            diag++;
        }
    }
    sort(should.begin(), should.end());
    for(int i = 0; i < v.size(); i++){
        if(should[i] != where[i]) tmp++;
    }
    ans = min(ans, tmp);
    tmp = 0, should.clear(), where.clear();
    
    //d2
    for(int i = 0; i < n; i++){
        int diag = 0;
        for(int j = m - 1; j >= 0; j--){
            if(grid[i][j] > -1){
                pos = (lower_bound(v.begin(), v.end(), grid[i][j]) - v.begin());
                where[pos] = diag + i;
                should.push_back(diag + i);
            }
            diag++;
        }
    }
    sort(should.begin(), should.end());
    for(int i = 0; i < v.size(); i++){
        if(should[i] != where[i]) tmp++;
    }
    ans = min(ans, tmp);
    tmp = 0, should.clear(), where.clear();

    //d3
    for(int i = n - 1; i >= 0; i--){
        int diag = 0;
        for(int j = m - 1; j >= 0; j--){
            if(grid[i][j] > -1){
                pos = (lower_bound(v.begin(), v.end(), grid[i][j]) - v.begin());
                where[pos] = diag + n - 1 - i;
                should.push_back(diag + n - 1 - i);
            }
            diag++;
        }
    }
    sort(should.begin(), should.end());
    for(int i = 0; i < v.size(); i++){
        if(should[i] != where[i]) tmp++;
    }
    ans = min(ans, tmp);
    tmp = 0, should.clear(), where.clear();

    //d4
    for(int i = n - 1; i >= 0; i--){
        int diag = 0;
        for(int j = 0; j < m; j++){
            if(grid[i][j] > -1){
                pos = (lower_bound(v.begin(), v.end(), grid[i][j]) - v.begin());
                where[pos] = diag + n - 1 - i;
                should.push_back(diag + n - 1 - i);
            }
            diag++;
        }
    }
    sort(should.begin(), should.end());
    for(int i = 0; i < v.size(); i++){
        if(should[i] != where[i]) tmp++;
    }
    ans = min(ans, tmp);
    tmp = 0, should.clear(), where.clear();
    cout << ans << "\n";
    return 0;
}