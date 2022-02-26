#include <bits/stdc++.h>

using namespace std;

const int N = 10;

//Número máximo coloque uma margem maior para não dar RTE (+5)
const int M = 15;

int v[N] = {10, 10, 10, 7, 6, 5, 5, 3, 1 , 1};
int ordv[N], cnt[M];

int main(){
    //conta quantos elementos com valor x existem
    for(int i = 0; i < N; i++){
        cnt[v[i]]++;
    }
    //Posição atual onde será colocada o valor atual
    int cur = 0;
    //Passa pelos valores, marcando a posição inicial a ser inserida
    for(int i = 0; i < M; i++){
        //enquanto o valor i existir no array, insere no vetor ordenado e incrementa a posição atual
        while(cnt[i]){
            ordv[cur] = i;
            //incrementa a posição para inserir o próximo valor
            cur++;
            cnt[i]--;
        }
    }
    for(int i = 0; i < N; i++) printf("%d ", ordv[i]);
}