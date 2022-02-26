//bibliotecas
#include <bits/stdc++.h>

//definindo std como padrão, isso é só para não escrever std:: antes de toda função (obs: em C isso não existe)
using namespace std;

int main(){
    //declaração
    int i;
    long l;
    char c;
    float f;
    double d;

    //leitura
    //cin >> i >> l >> c >> f >> d;
    scanf("%d %ld %c %f %lf",&i,&l,&c,&f,&d);

    //saída
    //cout << i << "\n" << l << "\n" << c << "\n";
    //cout << fixed;
    //cout << setprecision(3) << f << "\n";
    //cout << fixed;
    //cout << setprecision(9) << d << "\n";
    printf("%d\n%ld\n%c\n%0.3f\n%0.9lf\n",i,l,c,f,d);
    return 0;
}