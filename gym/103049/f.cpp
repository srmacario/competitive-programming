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

int n;
vi num;
pii pos_a, pos_b, moves[N];
map <pii, int> ini; 

int main(){
    srand(time(NULL));
    scanf("%d", &n);
    scanf("%d%d", &pos_a.st, &pos_a.nd);
    scanf("%d%d", &pos_b.st, &pos_b.nd);
    // moves[n] = {0,0};
    for(int i = 0; i < n; i++){
        num.pb(i+1);
        scanf("%d%d", &moves[i].st, &moves[i].nd);
        pii cur = {pos_a.st + moves[i].st, pos_a.nd + moves[i].nd};
        if(cur.st >= 1 and cur.st <= n and cur.nd >= 1 and cur.nd <= n){
            ini[cur]++;
        }
    }
    ini[pos_a]++;
    for(int i = 0; i < n; i++){
        pii cur = {pos_b.st - moves[i].st, pos_b.nd - moves[i].nd};
        if(cur.st >= 1 and cur.st <= n and cur.nd >= 1 and cur.nd <= n){
            // db(cur.st _ cur.nd);
            if(ini[cur]){
                printf("Alice wins\n");
                return 0;
            }
        }
    }
    ini.clear();
    for(int i = 0; i <= n; i++){
        pii cur = {pos_b.st + moves[i].st, pos_b.nd + moves[i].nd};
        db(cur.st _ cur.nd);
        if(cur.st >= 1 and cur.st <= n and cur.nd >= 1 and cur.nd <= n){
            ini[cur]++;
        }
    }
    ini[pos_b]++;
    // if(n > 1e5){
    //     for(int j = 0; j < 60; j++){
    //         mt19937 rng (chrono::system_clock::now().time_since_epoch().count());
    //         shuffle (num.begin(), num.end(), rng);
    //         pii tmp;
    //         tmp.st = num[0];
    //         mt19937 rng2 (chrono::system_clock::now().time_since_epoch().count());
    //         shuffle (num.begin(), num.end(), rng2);
    //         tmp.nd = num[0];
    //         for(int i = 0; i < n; i++){
    //             pii cur = {tmp.st - moves[i].st, tmp.nd - moves[i].nd};
    //             if(cur.st >= 1 and cur.st <= n and cur.nd >= 1 and cur.nd <= n){
    //                 if(!ini.count(cur)){
    //                     printf("tie %d %d\n", cur.st, cur.nd);
    //                     return 0;
    //                 }
    //             }
    //         }
    //     }
    // }
    // else{
    for(int k = 1; k <= n; k++){
        for(int j = 1; j <= n; j++){
            pii tmp = {j, k};
            if(tmp == pos_b) continue;
            for(int i = 0; i < n; i++){
                pii cur = {tmp.st - moves[i].st, tmp.nd - moves[i].nd};
                if(cur.st >= 1 and cur.st <= n and cur.nd >= 1 and cur.nd <= n){
                    db(cur.st _ cur.nd);
                    if(!ini.count(cur)){
                        printf("tie %d %d\n", cur.st, cur.nd);
                        return 0;
                    }
                }
            }
        }
    }
    // }
    printf("Bob wins\n");
    return 0;
}