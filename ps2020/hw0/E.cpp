//bibliotecas
#include <bits/stdc++.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
using namespace std;

int main(){
    //declaração de variáveis
    int a, b;
    
    //leitura
    // cin >> a >> b;
    scanf("%d %d", &a, &b);
    
    //loop
    //i recebe a, valor inicial.
    //condição de parada: enquanto i<=b o loop estará sendo executado
    //incremento: a cada fim execução do loop ele incrementa 1 na variavel i
    for(int i=a;i<=b;i++){
        if(i == 1){
            //cout << "one\n";
            printf("one\n");
        }
        else if(i == 2){
            //cout << "two\n";
            printf("two\n");
        }
        else if(i == 3){
            //cout << "three\n";
            printf("three\n");
        }
        else if(i == 4){
            //cout << "four\n";
            printf("four\n");
        }
        else if(i == 5){
            //cout << "five\n";
            printf("five\n");
        }
        else if(i == 6){
            //cout << "six\n";
            printf("six\n");
        }
        else if(i == 7){
            //cout << "seven\n";
            printf("seven\n");
        }
        else if(i == 8){
            //cout << "eight\n";
            printf("eight\n");
        }
        else if(i == 9){
            //cout << "nine\n";
            printf("nine\n");
        }
        else if((i%2) == 1){ //operador % indica resto: resto da divisão de i por 2. se for 1, o número é impar, se 0, é par.
            //cout << "odd\n";
            printf("odd\n");
        }
        else if((i%2) == 0){
            //cout << "even\n";
            printf("even\n");
        }
    }
    
    return 0;
}