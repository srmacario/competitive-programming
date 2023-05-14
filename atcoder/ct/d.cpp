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
const int N = 1e6+5;

int used[N];
set<int> num;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    cin >> w;
    for(int i = 1; i <= w;){
        pot.insert(i);
        i *= 2;
    }
    int current_pot = 1;
    int cnt = 0;
    for(int i = 1; i <= w; i++){
        if(pot.count(i)){
            used[i] = 1;
            num.insert(i);
            if(i > 1) current_pot *= 2;
        }
        else{
            int current = i - current_pot;
            if(used[current] == 3){
                used[current] = 1;
                num.insert(current);
                cnt++;
            }
            else used[current]++;
        }
    }
    cout << cnt << "\n";
    return 0;
}