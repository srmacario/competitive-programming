//bibliotecas
#include <bits/stdc++.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
using namespace std;

int max_of_four(int a, int b, int c, int d){
    int aux;
    // cin >> a >> b >> c >> d;
    scanf("%d %d %d %d",&a, &b, &c, &d);
    //testa primeiro qual maior entre a e b e salva o maior num auxiliar
    if(a>b) aux = a;
    else aux = b;
    //compara o auxiliar com o c, se c for maior, troca o auxiliar
    if(aux<c) aux = c;
    //repete o processo anterior com d
    if(aux<d) aux = d;
    //retorna a resposta
    return aux;
}

int main(){
    //declaração de variáveis
    int a,b,c,d;
    //cin >> a >> b >> c >> d;
    // executando a função
    //cout << max_of_four(a,b,c,d) << "\n";   
    printf("%d\n",max_of_four(a,b,c,d));
    return 0;
}