#include <bits/stdc++.h>
using namespace std;

int row[8]; // row[i] = qual linha esta a rainha da coluna i
// Isso já é uma otimização: não tem como ter mais de uma rainha por coluna
// e obrigatoriamente tem que ter uma rainha por coluna (são 8 rainhas no total
// e 8 colunas)

// checa se é possível colocar uma rainha na linha l e coluna c
bool check(int r, int c) {
  // como estamos colocando da primeira coluna pra ultima, só as rainhas das
  // colunas de 0 até c-1 foram colocadas

  // checa se a rainha na linha l e coluna c ataca alguma rainha que já foi
  // colocada
  for (int i = 0; i < c; i++) {
    // horizontal
    if (row[i] == r) return false;

    // diagonais
    if (row[i] + i == r + c) return false;
    if (row[i] - i == r - c) return false;
  }

  return true;
}

// backtracking colocando uma rainha na coluna c
// Invariante: já tem uma rainha em cada coluna de 0 até c-1 para
//             você poder chamar o backtracking pra coluna c

int total;
void bt(int c) {
  // caso base: se você já preencheu todo o tabuleiro
  // detalhe: toda recursão precisa de caso base, senão ela nunca vai acabar
  if (c == 8) {
    /*
    // imprime essa resposta
    // isso é bem verboso (escreve bastante no output, mas só pra demonstrar
    // que dá pra saber exatamente o estado do tabuleiro correto
    for (int i = 0; i < c; i++) {
      printf("%d %d\n", row[i], i);
    }
    printf("\n");
    */

    total++;
    return;
  }

  // tenta colocar a rainha da coluna c em cada uma das linhas
  for (int i = 0; i < 8; i++) {
    // checa se ela ataca alguma anterior
    if (check(i, c)) {
      // coloca a rainha na linha i
      row[c] = i;

      // se pode, avança para a prox coluna
      bt(c+1);

      // remove a rainha dessa coluna
      row[c] = -1;
    }
  }
}

int main() {
  bt(0);
  printf("%d\n", total); // só tem 92 casos

  return 0;
}
