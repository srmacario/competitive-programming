#include <bits/stdc++.h>

using namespace std;

//argumentos da função devem ser do mesmo tipo dos elementos da estrutura
typedef int tipo;

bool cmp(tipo a, tipo b){
    return a > b;
}

int v[10] = {1 , 2, 3, 4, 5, 6, 7, 7, 8, 9};

int main(){
    sort(v, v + 10, cmp);
    for(int i = 0; i < 10; i++) printf("%d\n", v[i]);
    return 0;
}