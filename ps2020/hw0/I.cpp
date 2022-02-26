//bibliotecas
#include <bits/stdc++.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
using namespace std;

//declaração de variáveis: declare arrays grandes globalmente!
int arr[1005], n;

int main(){
    //leitura
    //cin >> n;
    scanf("%d",&n);
    //atente: o indice do array começa em 0!
    for(int i=0;i<n;i++){
        //cin >> arr[i];
        scanf("%d",&arr[i]);
    }
    //saída
    //se eu tenho n numeros num array começando do inicio, o primeiro estará na posição 0 e o último na posição n-1
    for(int i=n-1;i>=0;i--){
        //cout << arr[i];
        printf("%d ",arr[i]);
    }

    return 0;
}