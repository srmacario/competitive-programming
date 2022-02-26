//bibliotecas
#include <bits/stdc++.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
using namespace std;

int main(){
    //declaração de variáveis
    int n, k, max_and = 0, max_or = 0, max_xor = 0;
    //leitura
    scanf("%d %d",&n,&k);
    //saída
    for(int a=1;a<=n;a++){
        //como na comparação, a<b, basta percorrer no segundo for por numeros maiores que a 
        for(int b=a+1;b<=n;b++){
            //verifica para cada par (a,b), a<b, se as condições pedidas pelo problema são resolvidas
            if((a&b) > max_and && (a&b)<k) max_and = a&b;

            if((a|b) > max_or && (a|b)<k) max_or = a|b;

            if((a^b) > max_xor && (a^b)<k) max_xor = a^b;
        }
    }
    printf("%d\n%d\n%d\n",max_and,max_or,max_xor);
    return 0;
}