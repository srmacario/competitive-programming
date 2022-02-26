//bibliotecas
#include <bits/stdc++.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
using namespace std;

int main(){
    //declaração de variáveis
    string a,b;
    //leitura
    cin >> a >> b;
    //saída
    cout << a.size() << " " << b.size() << "\n";
    cout << a+b << "\n";
    //uma função bem útil, troca o valor das variaveis, no caso troquei o valor de a[0] com b[0]
    swap(a[0],b[0]);
    cout << a << " " << b << "\n";
    return 0;
}