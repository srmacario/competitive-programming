#include<bits/stdc++.h>
using namespace std;

int n, k, t;
string s, ans;

string sum(string &a, string b){
    int c = 0;
    string d = "";
    for(int i = 0; i < max(a.size(), b.size()); i++){
        if(i < a.size())
            c += a[a.size() - i - 1] - '0';
        if(i < b.size())
            c += b[b.size() - i - 1] - '0';
        d += char('0' + c % 10);
        c /= 10;
    }
    if(c)
        d += char('0' + c);
    reverse(d.begin(), d.end());
    return d;
}

string smin(string &a, string &b){
    if(a.size() < b.size())
        return a;
    if(b.size() < a.size())
        return b;
    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i])
            return a;
        if(a[i] > b[i])
            return b;
    }
    return a;
}

void bt(int q = 0, int l = 0, string h = ""){
    if(l == s.size()){
        ans = smin(ans, h);
        return;
    }
    if(q < k)
        bt(q + 1, s.size(), sum(h, s.substr(l, s.size() - l)));
    if(q + 1 < k){
        if(l + n / k <= s.size())
            bt(q + 1, l + n / k, sum(h, s.substr(l, n / k)));
        if(l + n / k + 1 <= s.size())
            bt(q + 1, l + n / k + 1, sum(h, s.substr(l, n / k + 1)));
        if(l + n / k + 2 <= s.size())
            bt(q + 1, l + n / k + 2, sum(h, s.substr(l, n / k + 2)));
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        ans = s;
        k++;
        bt();
        cout << ans << '\n';
    }
}

/*
Quando uma exceção é lançada, o programa procura se consegue tratar a exceção imediatamente na função atual,
caso contrário, ele checa a função anterior que chamou a função atual. O programa continua esse processo de checar a stack function até encontrar um tratamento pra essa exceção que foi lançada.

Ao encontrar um tratamento pra exceção, a execução pula do ponto de onde a exceção foi lançada para o topo do bloco onde a exceção é tratada (bloco catch),
para isso, é necessário que ocorra um processo chamado de stack unwinding, que basicamente é remover as funções da call stack.
Ao ser executado o stack unwinding, os destrutores de todos os objetos e variaveis no caminho são chamados.

Aqui reside o problema de lança exceções nos destrutores, pois se colocarmos uma exceção no destrutor de algum objeto, o programa pode estar no stack unwinding e chamar um destrutor que lança uma exceção.
Assim, o compilador é colocado numa situação que não sabe se se continua o processo de stack unwinding ou se trata a nova exceção, como resultado, o programa é terminado imediatamente.

*/