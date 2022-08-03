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

int par[N], enemy[N], sz[N];

int find(int a) { 
    if(a == -1) return -1;
    return par[a] == a ? a : par[a] = find(par[a]);
}

//unite two groups
void unite(int a, int b) {
    if(a == -1 or b == -1) return;
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

bool process(int id, int a, int b) {
    //get the leader of group a and b
    int pa = find(a);
    int pb = find(b);
    //get the leader of group of enemy of leader a and leader b
    int en_a = find(enemy[pa]);
    int en_b = find(enemy[pb]);

    //check invalid union
    
    //set friends, but they are enemy
    if(id == 1 and (pa == en_b or en_a == pb)) return false;

    //set enemy, but they are friends
    if(id == 0 and (pa == pb)) return false;

    if(id == 1){
        //setting friendship
        //a and b are friends
        unite(a, b);
        //en_a and en_b are friends too
        unite(en_a, en_b);

        //change enemy pointers
        int p_friend = find(a);
        int p_enemy = find(en_a);
        if(p_enemy == -1) p_enemy = find(en_b);
        if(p_enemy != -1){
            enemy[p_enemy] = p_enemy;
            enemy[p_enemy] = p_friend;
        }
    }

    if(id == 0){
        //setting enemies
        //a and enemy of b are friends
        unite(a, en_b);
        //b and enemy of a are friends
        unite(en_a, b);

        //change enemy pointers
        int p_friend = find(a);
        int p_enemy = find(b);
        enemy[p_friend] = p_enemy;
        enemy[p_enemy] = p_friend;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    //initialize:
    //enemy[i]: pointer to the parent to the enemy group
    for(int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
    for(int i = 0; i < n; i++) enemy[i] = -1;

    while(true){
        int c, x, y;
        cin >> c >> x >> y;
        if(!c and !x and !y) return 0;
        if(c == 1){
            bool ok = process(1, x, y);
            if(!ok) cout << "-1\n";
        }
        if(c == 2){
            bool ok = process(0, x, y);
            if(!ok) cout << "-1\n";
        }
        if(c == 3){
            int px = find(x);
            int py = find(y);
            cout << (px == py) << "\n";
        }
        if(c == 4){
            int px = find(x);
            int py = find(y);
            int en_px = find(enemy[px]);
            int en_py = find(enemy[py]);
            if(px == en_py or py == en_px) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}