//bibliotecas
#include <bits/stdc++.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
using namespace std;

int main(){
    //declaração de variáveis
    int n;
    //leitura
    //cin >> n;
    scanf("%d",&n);
    //Condicionais
    if(n == 1){
        //cout << "one\n";
        printf("one\n");
    }
    else if(n == 2){
        //cout << "two\n";
        printf("two\n");
    }
    else if(n == 3){
        //cout << "three\n";
        printf("three\n");
    }
    else if(n == 4){
        //cout << "four\n";
        printf("four\n");
    }
    else if(n == 5){
        //cout << "five\n";
        printf("five\n");
    }
    else if(n == 6){
        //cout << "six\n";
        printf("six\n");
    }
    else if(n == 7){
        //cout << "seven\n";
        printf("seven\n");
    }
    else if(n == 8){
        //cout << "eight\n";
        printf("eight\n");
    }
    else if(n == 9){
        //cout << "nine\n";
        printf("nine\n");
    }
    else{
        //cout << "Greater than 9\n";
        printf("Greater than 9\n");
    }
    /* Algumas observações:
        Usar else if encadeia uma sequência de condições: testa o primeiro if, senão, testa o proximo else if e assim por diante até cair num else.
        No final, já botei um else de cara e printei "Greater than 9", se pensar no que o usuário poderia digitar, teria perigo de aparecer um número negativo e a minha condição estaria errada.
        Contudo, se perceber as restrições do problema, ele fala que: 1 <= n <= 10^9. Ou seja, ele nunca digitará um número negativo! Use as restrições ao seu favor para evitar programar coisas desnecessárias.
     */
    return 0;
}