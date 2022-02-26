//bibliotecas
#include <bits/stdc++.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
using namespace std;

int freq[10];
char s[1005];

int main(){
    //leitura
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
       if(s[i] - '0' <= 9 && s[i] - '0' >= 0) freq[s[i] - '0']++; 
    }
    //saída
    for(int i=0;i<=9;i++){
        printf("%d ",freq[i]);
    }
    return 0;
}