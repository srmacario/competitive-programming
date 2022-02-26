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
const int N = 15;

int grid[N][N], cur[N][N];
set <int> box[3][3], row[9], col[9];

void clean(){
    for(int i = 0; i < 9; i++) row[i].clear(), col[i].clear();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            box[i][j].clear();

        }
    }
}

bool test(int i, int j, int k){
    if(!box[i/3][j/3].count(k) and !row[i].count(k) and !col[j].count(k)) return true;
    return false;
}

void add(int i, int j, int k){
    box[i/3][j/3].insert(k);
    row[i].insert(k);
    col[j].insert(k);
}

void rem(int i, int j, int k){
    box[i/3][j/3].erase(k);
    row[i].erase(k);
    col[j].erase(k);
}

void print(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d ", cur[i][j]);
        }
        printf("\n");
    }
}

bool bt(int i, int j){
    //iterando nas colunas
    // condição de parada: chegou numa linha inexistente, sudoku completo
    if(i == 9){
        return true;
    }
    //chegou numa coluna inexistente, reseta e começa da linha seguinte
    if(j == 9){
        return bt(i+1, 0);
    }
    if(!grid[i][j]){
        for(int k = 1; k <= 9; k++){
           if(test(i, j, k)){
               bool ok = false;
               //adiciona k à resposta 
               cur[i][j] = k;
               add(i, j, k);
               ok = bt(i, j+1);
               //se voltou da recursão com true, quer dizer que chegou até o fim: sudoku completo
               if(ok) return true;
               //caso contrário, remove e prossegue testando
               cur[i][j] = 0;
               rem(i, j, k);
           } 
        }
        return false;
    }
    else{
        //chegou numa posição preenchida, basta seguir
        return bt(i, j+1);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        clean();
        bool ok = true;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &grid[i][j]);
                cur[i][j] = grid[i][j];
                if(grid[i][j]){
                    ok = test(i, j, grid[i][j]);
                    add(i, j, grid[i][j]);
                }
            }
        }
        if(ok){
            if(bt(0,0)){
                print();
                continue;
            }
        }
        printf("No solution\n");
    }
    return 0;
}