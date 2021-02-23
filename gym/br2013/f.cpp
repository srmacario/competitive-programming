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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,g;
    while(cin >> n >> g){
        int cnt = 0;
        vi game;
        for(int i=0;i<n;i++){
            int s,r;
            cin >> s >> r;
            game.pb(r-s);
        }
        sort(game.begin(), game.end());
        for(int i=0;i<n;i++){
            if(game[i] < 0) cnt += 3 ;
            if(game[i] == 0){
                cnt += 1;
                if(g) cnt+=2, g--;
            }
            if(game[i] > 0){
                if(g >= game[i]){
                    cnt += 1, g-=game[i];
                    if(g) cnt+=2, g--;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}