#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int grid[N][N], cnt, ans, queens[N];
vector<vector<int>> all;

void add(int i, int j){
    for(int k=0;k<8;k++) grid[i][k]++;
    for(int k=0;k<8;k++) grid[k][j]++;
    int k = 1;
    while(i-k >= 0 and j-k >= 0) grid[i-k][j-k]++, k++; k=1;
    while(i+k < 8 and  j-k >= 0) grid[i+k][j-k]++, k++; k=1;
    while(i-k >= 0 and j+k < 8) grid[i-k][j+k]++, k++; k=1;
    while(i+k < 8 and j+k < 8) grid[i+k][j+k]++, k++; k=1;
    grid[i][j]--;
}
void rem(int i, int j){
    for(int k=0;k<8;k++) grid[i][k]--;
    for(int k=0;k<8;k++) grid[k][j]--;
    int k = 1;
    while(i-k >= 0 and j-k >= 0) grid[i-k][j-k]--, k++; k=1;
    while(i+k < 8 and  j-k >= 0) grid[i+k][j-k]--, k++; k=1;
    while(i-k >= 0 and j+k < 8) grid[i-k][j+k]--, k++; k=1;
    while(i+k < 8 and j+k < 8) grid[i+k][j+k]--, k++; k=1;
    grid[i][j]++;
}
void print(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            printf("%d ",grid[i][j]);
        printf("\n");
    }
}
void bt(int r, int c){
    /*  
        Condição de parada do backtracking:
        8 rainhas foram colocadas no tabuleiro
    */
    if(cnt == 8){
        //Dado que todas foram colocadas, incrementamos a resposta
        vector<int> aux;
        for(int i=0;i<8;i++) aux.push_back(queens[i]);
        all.push_back(aux);
        ans++;
        return;
    }
    //chegamos ao limite de colunas, para aquela configuração não é possível prosseguir, é necessário retroceder
    if(c>=8) return;
    //verifica se aquela posição é proibida
    if(grid[r][c]){
        //posição proibida, tenta colocar na próxima
        bt(r,c+1);
        return;
    }
    //chegou aqui, então não é posição proibida
    //insere a rainha na posição
    add(r,c), queens[cnt] = c, cnt++;
    //chama a próxima posição
    bt(r+1,0);
    //após terminado o teste com aquela posição, remove ela dali e coloca na próxima e reinicia o algoritmo
    rem(r,c), queens[cnt] = -1, cnt--;
    bt(r,c+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, row, col;
    cin >> t;
    memset(queens, -1, sizeof(queens));
    bt(0,0);
    while(t--){
        cin >> row >> col;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        vector <vector<int>> sol;
        int soln = 0;
        for(int i=0;i<ans;i++){
            if(all[i][col-1] == row-1) sol.push_back(all[i]), soln++;
        }
        for(int i=0;i<soln;i++){
            if(i+1 <= 9) cout << " ";
            cout << i+1 << "      ";
            for(int j=0;j<8;j++){
                cout << sol[i][j]+1;
                if(j!=7) cout << " ";
            }
            if(i!=soln-1) cout << "\n";
        }
        if(t) cout << "\n\n";
    }
    cout << "\n";
    //cout << ans << "\n";
    return 0;
}