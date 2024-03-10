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

int comb[1 << 7], m = 0;
vector<int> which[8];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int k = 1;
    comb[0] = n;
    for(int i = 1; i < (1 << 7) and k < n; i++, k++){
        comb[i] = k;
        for(int j = 0; j < 7; j++){
            if((1 << j) & i){
                which[j + 1].push_back(k);
                m = max(j + 1, m);
            }
        }
    }
    cout << m << endl;
    for(int i = 1; i <= m; i++){
        cout << which[i].size() << " ";
        for(auto b : which[i]){
            cout << b << " ";
        }
        cout << endl;
    }
    string s;
    cin >> s;
    int num = 0;
    for(int i = 0; i < m; i++){
        num += ((s[i] - '0') << i);
    }
    cout << comb[num] << "\n";
    return 0;
}

/*
4 3
1 2 
  2 3


6 3         7   
1     4 5   7
  2   4   6 7
    3   5 6 7
      
*/