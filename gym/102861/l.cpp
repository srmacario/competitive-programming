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
const int N = 55;

int l,c,n,p;
string grid[N], q[N];
int ans[N][N][N];
int resp[N][N];

void ver(int pos, int row, int col){
    if(row + q[pos].size() - 1 >= l) return;
    int ana[26] = {0}, pal[26] = {0};
    for(int add = 0;add<q[pos].size();add++){
        ana[grid[row+add][col] - 'A']++;
        pal[q[pos][add] - 'A']++;
    }
    for(int i=0;i<26;i++){
        if(ana[i] != pal[i]) return;
    }
    for(int add=0;add<q[pos].size();add++){
        ans[pos][row+add][col] = 1;
    }
}

void hoz(int pos, int row, int col){
    if(col + q[pos].size() - 1 >= c) return;
    int ana[26] = {0}, pal[26] = {0};
    for(int add = 0;add<q[pos].size();add++){
        ana[grid[row][col+add] - 'A']++;
        pal[q[pos][add] - 'A']++;
    }
    for(int i=0;i<26;i++){
        if(ana[i] != pal[i]) return;
    }
    for(int add = 0;add<q[pos].size();add++){
        ans[pos][row][col+add] = 1;
    }
}

void d1(int pos, int row, int col){
    if(col + q[pos].size() - 1 >= c) return ;
    if(row + q[pos].size() - 1 >= l) return;
    int ana[26] = {0}, pal[26] = {0};
    for(int add = 0;add<q[pos].size();add++){
        ana[grid[row+add][col+add] - 'A']++;
        pal[q[pos][add] - 'A']++;
    }
    for(int i=0;i<26;i++){
        if(ana[i] != pal[i]) return;
    }
    for(int add = 0;add<q[pos].size();add++){
        ans[pos][row+add][col+add] = 1;
    }
}

void d2(int pos, int row, int col){
    if(col - q[pos].size() + 1 < 0) return;
    if(row + q[pos].size() - 1 >= l) return;
    int ana[26] = {0}, pal[26] = {0};
    for(int add = 0;add<q[pos].size();add++){
        ana[grid[row+add][col-add] - 'A']++;
        pal[q[pos][add] - 'A']++;
    }
    for(int i=0;i<26;i++){
        if(ana[i] != pal[i]) return;
    }
    for(int add = 0;add<q[pos].size();add++){
        ans[pos][row+add][col-add] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> c;
    for(int i=0;i<l;i++) cin >> grid[i];
    cin >> p;
    for(int i=0;i<p;i++) cin >> q[i];
    for(int i=0;i<p;i++){
        for(int j=0;j<l;j++){
            for(int k=0;k<c;k++){
                ver(i,j,k);
                hoz(i,j,k);
                d1(i,j,k);
                d2(i,j,k);
            }
        }
        for(int j=0;j<l;j++){
            for(int k=0;k<c;k++){
                resp[j][k] += ans[i][j][k];
            }
        }
    }
    int total = 0;
    for(int j=0;j<l;j++){
        for(int k=0;k<c;k++){
            if(resp[j][k] > 1) total++;
        }
    }
    cout << total << "\n";
    return 0;
}