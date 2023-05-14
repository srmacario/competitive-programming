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
const int N = 10;

int grid[N][N], cur[N][N];
set <int> zig[N], zag[N], box[N][N];

int zig_ind(int i, int j){
    if(j > i) return (j-i);
    return (j+9-i);
}

int zag_ind(int i, int j){
    return (i+j)%9;
}

void clean(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            zig[zig_ind(i,j)].clear(), zag[zag_ind(i,j)].clear();
            grid[i][j] = cur[i][j] = 9;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            box[i][j].clear();
        }
    }
}

bool test(int i, int j, int k){
    if(!box[i/3][j/3].count(k) and !zig[zig_ind(i,j)].count(k) and !zag[zag_ind(i,j)].count(k)) return true;
    return false;
}

void add(int i, int j, int k){
    box[i/3][j/3].insert(k);
    zig[zig_ind(i,j)].insert(k);
    zag[zag_ind(i,j)].insert(k);
}

void rem(int i, int j, int k){
    box[i/3][j/3].erase(k);
    zig[zig_ind(i,j)].erase(k);
    zag[zag_ind(i,j)].erase(k);
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
    if(grid[i][j] == 9){
        for(int k = 0; k <= 8; k++){
           if(test(i, j, k)){
               bool ok = false;
               //adiciona k à resposta 
               cur[i][j] = k;
               add(i, j, k);
               ok = bt(i, j+1);
               //se voltou da recursão com true, quer dizer que chegou até o fim: sudoku completo
               if(ok) return true;
               //caso contrário, remove e prossegue testando
               cur[i][j] = 9;
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
    int n, sum = 0;
    scanf("%d", &n);
    while(n--){
        clean();
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c;
                scanf(" %c", &c);
                if(c == '.'){
                    grid[i][j] = 9;
                }
                else{
                    grid[i][j] = c - '0';
                    add(i, j, grid[i][j]);
                }
                cur[i][j] = grid[i][j];
            }
        }
        // cout << "\n";
        bt(0,0);
        // print();
        sum += cur[0][0];
    }
    printf("%d\n", sum);
    return 0;
}