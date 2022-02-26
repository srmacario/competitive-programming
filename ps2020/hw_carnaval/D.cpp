#include <bits/stdc++.h>

using namespace std;

int a[200];

int main(){
    int n, first_neg = 0, second_neg = 0,cnt = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        //contando quantos negativos existem na sequência, mais tarde será útil
        if(a[i] < 0) cnt++;
        // se o contador for um e ainda não existir um first_neg
        if(cnt == 1 and first_neg == 0) first_neg = a[i];
        //se o contador for dois e ainda não existir um second_neg
        if(cnt == 2 and second_neg == 0) second_neg = a[i];
    }
    /*
        Note que ele fala que todas as soluções existem, então existe um zero.
    */
    //imprime o primeiro conjunto
    cout << "1 " << first_neg << "\n";
    //imprimindo o número de elementos do conjunto positivo, se existirem par números de negativos, serão n-3 números no positivo (todos, exceto dois negativos e o 0)
    if(cnt%2 == 0) cout << n-3 << " ";
    //caso contrário, serão n-2(todos, exceto um negativo e o 0)
    else cout << n-2 << " ";
    for(int i=0;i<n;i++){
        // imprimindo o conjunto dos positivos
        /* Explicando as condições para imprimir os positivos:
            1ª: o número é diferente do primeiro negativo, pois eu ja imprimi ele no conjunto dos negativos
            2ª: o número é diferente de zero, pois ele estará no conjunto do zero
            3ª: se o numero de ímpares for par, precisamos pegar um segundo negativo e jogar no conjunto do zero, para garantir que existem números pares de negativos,
                garantindo a positividade do segundo conjunto.
                Por hora, não vou imprimir o segundo negativo, e depois checo se ele entra nesse grupo ou não
        */
        if((a[i]!=first_neg) and (a[i]!=0) and (a[i]!=second_neg)) cout << a[i] << " ";
    }
    //se for número ímpar de negativos e um second_neg existir, imprime agora, senão, só imprime no conjunto do 0
    if(cnt%2 == 1 and second_neg != 0) cout << second_neg << "\n";
    else cout << "\n";
    //imprimindo o conjunto do 0
    if(cnt%2 == 0) cout << "2 0 " << second_neg << "\n"; 
    else cout << "1 0\n";
    return 0;
}