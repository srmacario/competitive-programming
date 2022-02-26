//bibliotecas
//#include <bits/stdc++.h>
#include <stdio.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
//using namespace std;

//declaração de variáveis
int n, sz, matriz[3005][3005];
//declare matriz ou arrays usando valores um pouco maiores que as restrições
//na competição, geralmente declaramos uma array grando baseado nas restrições, assim sabemos o tamanho maximo que usaremos

int main(){
    //leitura
    //cin >> n;
    scanf("%d",&n);
    //perceba que a dimensão da matriz é (2*n-1) x (2*n - 1);
    sz = 2*n-1;
    //saída
    /* preenchendo as linhas com os numeros:
        ex: preenchendo a primeira linha e ultima com n
            preenchendo a segunda e a penultima com n-1 e assim por diante.
        para visualizar melhor, imprima a matriz na tela após essa sequência de for's
    */
    for(int i=0;i<n;i++){
        for(int j=i;j<sz-i;j++){
            matriz[i][j] = matriz[sz-1-i][j] = n-i;
        }
    }
    /* preenchendo as colunas com os numeros:
        ex: preenchendo a primeira colunas e ultima com n
            preenchendo a segunda e a penultima com n-1 e assim por diante.
        para visualizar melhor, imprima a matriz na tela após essa sequência de for's
        basicamente é a mesma sequência da anterior, mas espelhada
    */
    for(int i=0;i<n;i++){
        for(int j=i;j<sz-i;j++){
            matriz[j][i] = matriz[j][sz-1-i] = n-i;
        }
    }
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}