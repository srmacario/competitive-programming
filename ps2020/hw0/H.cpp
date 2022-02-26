//bibliotecas
#include <bits/stdc++.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
using namespace std;

//declaração de variáveis
int a,b,c,n;

int series(int n){
    //condições de parada
    if(n == 1) return a;
    if(n == 2) return b;
    if(n == 3) return c;
    //segue a recorrência
    return series(n-1) + series(n-2) + series(n-3);
}

int main(){
    //leitura
    //cin >> n >> a >> b >> c;
    scanf("%d %d %d %d",&n, &a, &b, &c);
    //saída
    //cout << series(n) << "\n";
    printf("%d\n",series(n));
    return 0;
}