#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N],freq[N];

/* Essa estrutura é nova pra alguns, será detalhada mais a frente.
    Mas adiantando, um vector é um array dinâmico, que não precisa ser declarado o tamanho, quando quisermos inserir um elemento, ele é inserido no final.
*/
vector <int> not_used;

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        //incrementa a frequência do número lido
        freq[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        //se a frequência de i for 0, ele não foi usado
        //para adicionar em um vector, basta dar push_back(x), onde x é o elemento a ser adicionado
        if(freq[i] == 0) not_used.push_back(i);
    }
    for(int i=1;i<=n;i++){
        //se não tiver mas nenhum número não sendo usado, a permutação está feita
        if(not_used.size() == 0) break;
        //se a frequência daquele número for maior que 1, precisamos trocá-lo, ou também se o número do a[i] for maior que n
        if(freq[a[i]] > 1 or a[i] > n){
            //diminui a frequência do número que vamos trocar
            freq[a[i]]--;
            //atribui àquele número repetido, o valor de um não usado
            a[i] = not_used.back();
            //remove o não usado da lista
            not_used.pop_back();
        }
    }
    //saída
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << "\n";
    return 0;
}