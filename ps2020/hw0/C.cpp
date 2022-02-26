//bibliotecas
#include <bits/stdc++.h>

//definindo std como padrão, isso é só para não escrever std:: antes de toda função (obs: em C isso não existe)
using namespace std;

int main(){
    //declaração
    int x,y;
    float a,b;
    //leitura
    //cin >> x >> y >> a >> b;
    scanf("%d %d %f %f", &x, &y, &a, &b);
    //saída
    //cout << x + y << " " << x - y << "\n";
    //cout << fixed << setprecision(1) << a + b << " " << a - b << "\n";
    //setprecision define a precisão da sua resposta: numero de casas decimais + 1 
    printf("%d %d\n",x+y,x-y);
    printf("%0.1f %0.1f\n",a+b,a-b);
    return 0;
}