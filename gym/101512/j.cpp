#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " << 

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int grid [400][400];
char cur = 'R';

pii dx(char c1, char dir){
    if(dir == 'R'){
        if(c1 == 'R') cur = dir = 'S'; 
        if(c1 == 'L') cur = dir = 'N';
        if(c1 == 'S') cur = dir = 'L';
        if(c1 == 'N') cur = dir = 'R';
    }
    else if(dir == 'L'){
        if(c1 == 'R') cur = dir = 'N'; 
        if(c1 == 'L') cur = dir = 'S';
        if(c1 == 'S') cur = dir =  'R';
        if(c1 == 'N') cur = dir =  'L';
    }
    else if(dir == 'B'){
        if(c1 == 'R') cur = dir =  'L'; 
        if(c1 == 'L') cur = dir =  'R';
        if(c1 == 'S') cur = dir =  'N';
        if(c1 == 'N') cur = dir =  'S';
    }
    else dir = c1;
    if(dir == 'R') return {0,1};
    if(dir == 'L') return {0,-1};
    if(dir == 'N') return {-1,0};
    if(dir == 'S') return {1,0};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cout << t << "\n";
    while(t--){
        string s;
        cin >> s;
        cur = 'R';
        pii pos = {200,0};
        grid[pos.st][pos.nd] = 1;
        int top = 400, bot = 0, right = 0;
        for(int i=0;i<s.size();i++){
            pii to = dx(cur,s[i]);
            pos.st += to.st, pos.nd += to.nd;
            top = min(top,pos.st);
            bot = max(bot,pos.st);
            right = max(right,pos.nd);
            if(pos.st >= 0 and pos.nd >= 0) grid[pos.st][pos.nd] = 1;
        }
        cout << bot - top + 3 << " " << right + 2 << "\n";
        for(int i=top-1;i<=bot+1;i++){
            for(int j = 0; j <= right+1; j++){
                cout << (grid[i][j] ? '.' : '#');
            }
            cout << "\n";
        }
        memset(grid,0,sizeof(grid));
    }
    return 0;
}