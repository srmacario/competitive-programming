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

set<int> row[50], col[50];
int n;
string s[50];

int id(char c){
    if(c >= 'A' and c <= 'Z') return (c - 'A') + 10;
    return c - '0';
}

bool check_latin(){
    for(int i = 0; i < n; i++){
        if((row[i].size() != n) or (col[i].size() != n)) return false;
    }
    return true;
}

bool check_red(){
    if(s[0][0] != '0') return false;
    for(int i = 1; i < n; i++){
        if(id(s[i][0]) != (id(s[i - 1][0]) + 1)) return false;
        if(id(s[0][i]) != (id(s[0][i - 1]) + 1)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n){
        for(int i = 0; i < n; i++){
            row[i].clear(), col[i].clear();
        }
        for(int i = 0; i < n; i++){
            cin >> s[i];
            for(int j = 0; j < n; j++){
                row[i].insert(id(s[i][j]));
                col[j].insert(id(s[i][j]));
            }
        }
        if(!check_latin()){
            cout << "No\n";
        }
        else{
            if(check_red()){
                cout << "Reduced\n";
            }
            else{
                cout << "Not Reduced\n";
            }
        }
    }
    return 0;
}