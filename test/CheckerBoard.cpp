#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void changeColor(int desiredColor){ 
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 

enum Tipo {vazio, comum, rainha};
enum Dono {jogador, computador, ninguem};
class Peca {
private:
	Tipo t;
	int fila;
	int coluna;
	Dono dono;
	bool comeu; //vai ser usado para saber se o movimento valido come ou nao uma peca
public:
	Peca (Tipo t, int coluna, int fila, Dono dono): t(t), coluna(coluna), fila(fila), dono(dono), comeu(false){
	}
	void setfila(int fila){this->fila = fila;}
    int getfila() const{return fila;}
    void setcoluna(int coluna){this->coluna = coluna;}
    int getcoluna() const{return coluna;}
    Dono getdono() const{return dono;}
    Tipo gettipo(){return t;}
    void settipo(Tipo ti) { t = ti;}
    void setdono(Dono d) { dono = d;}
    void setrainha() {t = rainha;}
    bool getcomeu() {return comeu;}
    void setcomeu(bool c) { comeu = c;}
    virtual bool jogada(Peca*[8][8], int ,int , int) = 0;
    static int pecasjogador;
    static int pecascomputador;
	
};
int Peca::pecasjogador = 12;
int Peca::pecascomputador = 12;

class Vazio:public Peca {
public:
	Vazio(int coluna,int fila,Dono dono): Peca(vazio, coluna, fila, ninguem){
	}
	bool jogada(Peca *tabuleiro[8][8],int colunaf,int filaf, int teste) {
		return false;
	}
};

class Rainha:public Peca {
public:
	Rainha(int coluna,int fila,Dono dono): Peca(rainha, coluna, fila, dono){
	}
	bool jogada(Peca *tabuleiro[8][8],int colunaf,int filaf, int teste) {
		if(colunaf > 7 or colunaf < 0 or filaf > 7 or filaf < 0) //jogada fora do tabuleiro
			return false;
		else{
				if(abs(colunaf - getcoluna()) == abs(filaf - getfila())) { //movimento nas diagonais
					if(tabuleiro[colunaf][filaf]->gettipo() == vazio) { //posicao final deve estar vazia
						if(colunaf > getcoluna() and filaf > getfila()) { //movimento direita, cima
							for(int i = 1; i <= (colunaf - getcoluna()) - 2; i++) { //so pode andar se todos os campos desde a proxima ate a antipenultima nao estao ocupados (so eh possivel comer uma peca)
								if(tabuleiro[getcoluna() + i][getfila() + i]->getdono() != ninguem)
									return false;
							}
							//penultimacasa desocupada ou quando a penultima coincide com a ultima
							if(tabuleiro[colunaf-1][filaf-1]->getdono() == ninguem or ((colunaf -1) == getcoluna() and (filaf-1) == getfila() and tabuleiro[colunaf-1][filaf-1]->getdono() == getdono() )) {
								if(teste == 0) {
									tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
									tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
									return true;
								}
								else {
									return true;
								}
							}
							//quando ele come a peca na penultima posicao
							else if(tabuleiro[colunaf-1][filaf-1]->getdono() != getdono()) {
								if(teste == 0) {
									if(getdono() == jogador) 
										pecascomputador--;
									else 
										pecasjogador--;
				            		tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
									tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
									tabuleiro[colunaf-1][filaf-1] = new Vazio(colunaf-1, filaf-1, ninguem);
									return true;
								}
								else {
									setcomeu(true);
									return true;
								}
							}
							else	
								return false;
							
						}
						else if(colunaf < getcoluna() and filaf > getfila()) { //movimento esquerda, cima
							for(int i = 1; i <= (getcoluna() - colunaf)- 2; i++) {
								if(tabuleiro[getcoluna() - i][getfila() + i]->getdono() != ninguem)
									return false;
							}
							if(tabuleiro[colunaf+1][filaf-1]->getdono() == ninguem or ((colunaf+1) == getcoluna() and (filaf-1) == getfila() and tabuleiro[colunaf+1][filaf-1]->getdono() == getdono() )) {
								if(teste == 0) {
									tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
									tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
									return true;
								}
								else {
									return true;
								}
							}
							else if(tabuleiro[colunaf+1][filaf-1]->getdono() != getdono()) {
								if(teste == 0) {
									if(getdono() == jogador) 
										pecascomputador--;
									else 
										pecasjogador--;
				            		tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
									tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
									tabuleiro[colunaf+1][filaf-1] = new Vazio(colunaf+1, filaf-1, ninguem);
									return true;
								}
								else {
									setcomeu(true);
									return true;
								}
							}
							else	
								return false;	
						}
						else if(colunaf > getcoluna() and filaf < getfila()) { //movimento direita, baixo
							for(int i = 1; i <= (colunaf - getcoluna())- 2; i++) {
								if(tabuleiro[getcoluna() + i][getfila() - i]->getdono() != ninguem)
									return false;
							}
							if(tabuleiro[colunaf-1][filaf+1]->getdono() == ninguem or ((colunaf -1) == getcoluna() and (filaf+1) == getfila() and tabuleiro[colunaf-1][filaf+1]->getdono() == getdono() )) {
								if(teste == 0) {
									tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
									tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
									return true;
								}
								else {
									return true;
								}
							}
							else if(tabuleiro[colunaf-1][filaf+1]->getdono() != getdono()) {
								if(teste == 0) {
									if(getdono() == jogador) 
										pecascomputador--;
									else 
										pecasjogador--;
				            		tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
									tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
									tabuleiro[colunaf-1][filaf+1] = new Vazio(colunaf-1, filaf+1, ninguem);
									return true;
								}
								else {
									setcomeu(true);
									return true;
								}
							}
							else	
								return false;	
						}
						else if(colunaf < getcoluna() and filaf < getfila()) { //movimento esquerda, baixo
							for(int i = 1; i <= (getcoluna() - colunaf)- 2; i++) {
								if(tabuleiro[getcoluna() - i][getfila() - i]->getdono() != ninguem)
									return false;
							}
							if(tabuleiro[colunaf+1][filaf+1]->getdono() == ninguem or ((colunaf +1) == getcoluna() and (filaf+1) == getfila() and tabuleiro[colunaf+1][filaf+1]->getdono() == getdono() )) {
								if(teste == 0) {
									tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
									tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
									return true;
								}
								else {
									return true;
								}
							}
							else if(tabuleiro[colunaf+1][filaf+1]->getdono() != getdono()) {
								if(teste == 0) {
									if(getdono() == jogador) 
										pecascomputador--;
									else 
										pecasjogador--;
				            		tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
									tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
									tabuleiro[colunaf+1][filaf+1] = new Vazio(colunaf+1, filaf+1, ninguem);
									return true;
								}
								else {
									setcomeu(true);
									return true;
								}
							}
							else	
								return false;	
						}
						else
							return false;
					}
					else
						return false;
				}
				else
					return false;
		}	
	}
};

class Comum:public Peca {
public:
	Comum(int coluna,int fila,Dono dono): Peca(comum, coluna, fila, dono){
	}
	bool jogada(Peca *tabuleiro[8][8], int colunaf, int filaf, int teste) {
		if(colunaf > 7 or colunaf < 0 or filaf > 7 or filaf < 0) {
			return false;
		}
		else {
			//o jogador so pode subir na fila e o computador so pode descer na fila, mas ambos podem andar pros dois lados da coluna
			if((getdono() == jogador and filaf == getfila() + 1) or (getdono() == computador and filaf == getfila() - 1)) {
				if((colunaf == getcoluna() + 1 or colunaf == getcoluna() - 1) and tabuleiro[colunaf][filaf]->gettipo() == vazio) {
					if(teste == 0) {
						tabuleiro[colunaf][filaf] = new Comum(colunaf, filaf, getdono());
						tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
	               		
	                	if((filaf == 7 and getdono() == jogador) or (filaf== 0 and getdono() == computador)) {
	                		tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
	                		//cout << tabuleiro[getcoluna()][getfila()]->gettipo() << "\n";
	                		//cout << tabuleiro[getcoluna()][getfila()]->getdono() << "\n";
	                		
						}
	               		return true;
					}
					else {
						return true;
					}
				}
				else {
					return false;
				}	
			}
			else if(getdono() == jogador and filaf == getfila() + 2){
				if((colunaf == getcoluna() + 2 or colunaf == getcoluna() -2) and tabuleiro[colunaf][filaf]->gettipo() == vazio) {
					if(colunaf > getcoluna()) {
						if(tabuleiro[colunaf-1][filaf-1]->getdono() != computador)
							return false;
					}
					if(colunaf < getcoluna()) {
						if(tabuleiro[colunaf+1][filaf-1]->getdono() != computador)
							return false;
					}
					if(teste == 0) {
						pecascomputador--;
						tabuleiro[colunaf][filaf] = new Comum(colunaf, filaf, getdono());
						tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
						if(colunaf > getcoluna())
							tabuleiro[colunaf-1][filaf-1] = new Vazio(colunaf-1, filaf-1, ninguem);
						else
							tabuleiro[colunaf+1][filaf-1] = new Vazio(colunaf+1, filaf-1, ninguem);
	                	if(filaf == 7) {
	                		tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
						}
						return true;
					}
					else {
						setcomeu(true);
						return true;
					}
				}
				else {
					return false;
				}

			}
			else if(getdono() == computador and filaf == getfila() - 2) {
				if((colunaf == getcoluna() + 2 or colunaf == getcoluna() - 2) and tabuleiro[colunaf][filaf]->gettipo() == vazio) {
					if(colunaf > getcoluna()) {
						if(tabuleiro[colunaf-1][filaf+1]->getdono() != jogador)
							return false;
					}
					if(colunaf < getcoluna()) {
						if(tabuleiro[colunaf+1][filaf+1]->getdono() != jogador)
							return false;
					}
					if(teste == 0) {
						pecasjogador--;
		            	tabuleiro[colunaf][filaf] = new Comum(colunaf, filaf, getdono());
						tabuleiro[getcoluna()][getfila()] = new Vazio(getcoluna(), getfila(), ninguem);
						if(colunaf > getcoluna())
							tabuleiro[colunaf-1][filaf+1] = new Vazio(colunaf-1, filaf+1, ninguem);
						else
							tabuleiro[colunaf+1][filaf+1] = new Vazio(colunaf+1, filaf +1, ninguem);
		                if(filaf == 0) {
		                	tabuleiro[colunaf][filaf] = new Rainha(colunaf, filaf, getdono());
						}
						return true;
					}
	                else {
						setcomeu(true);
						return true;
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}		
	}
};



class Dama {
private:
	Dono vez;
	int inicio;
	bool gameover;
public:
	Peca *tabuleiro[8][8];
	Dama(): gameover(false), vez(jogador), inicio(1) {
		for(int fila = 0; fila < 8; fila++) {
			for(int coluna = 0; coluna < 8; coluna++) {
				if(fila != 3 and fila != 4) {
					if((fila + coluna)%2 == 0 and fila <=2)
						tabuleiro[coluna][fila] =  new Comum(coluna, fila, jogador);
					else if((fila + coluna)%2 == 0 and fila >2)
						tabuleiro[coluna][fila] =  new Comum(coluna, fila, computador);
					else
						tabuleiro[coluna][fila] =  new Vazio(coluna, fila, ninguem);
				}
				else
					tabuleiro[coluna][fila] =  new Vazio(coluna, fila, ninguem);
			}
		}
	}
	~Dama() {
		for(int j = 0; j < 8; j++) {
			for(int i = 0; i< 8; i++) {
				delete tabuleiro[j][i];
			}
 		}
	}
	bool FimdoJogo() {
		if(gameover) {
			if(vez == jogador)
				cout << "Fim do Jogo! Vencedor: jogador\n";
			else
				cout << "Fim do Jogo! Vencedor: computador\n";
			return true;
		}
		else
			return false;
	}
	bool jogador_preso() { //vai retornar o caso em que nao ha mais jogadas possiveis para o cara da vez
		for(int j = 0; j < 8; j++) {
			for(int i = 0; i < 8; i++) {
				for(int k = 0; k < 8; k ++) {
					for(int l = 0; l < 8; l++) {
						if(tabuleiro[j][i]->getdono() != tabuleiro[k][l]->getdono()) {
							if(tabuleiro[j][i]->jogada(tabuleiro, k,l,1))
								return false;
						}
					}
				}
			}
		}
		return true;
	}
	string jogada_computador() {
		vector<pair<pair<int, int>, pair<int, int>>> movimentosemcomer;
		vector<pair<pair<int, int>, pair<int, int>>> movimentodecomer;
		vector<pair<pair<int, int>, pair<int, int>>> movimentorainha;
		int colunafinal, colunainicial, filainicial, filafinal;
		string lance;
		for(int j = 0; j < 8; j++) {
			for(int i = 0; i < 8; i++) {
				if(tabuleiro[j][i]->getdono() == computador) {
					for(int k = 0; k < 8; k++) {
						for(int l = 0; l < 8; l++) {
							if(tabuleiro[j][i]->jogada(tabuleiro, k, l, 1)) {
								if(l == 0) {
									movimentorainha.push_back({{j, i}, {k, l}});
								}
								else if(tabuleiro[j][i]->getcomeu()) {
									movimentodecomer.push_back({{j, i}, {k, l}});
									//cout << j << " " << i << " " << k << " " << l << " comendo\n";
									tabuleiro[j][i]->setcomeu(false);
								}
								else {
									movimentosemcomer.push_back({{j, i}, {k, l}});
									//cout << j << " " << i << " " << k << " " << l << " semcomer\n";
								}
							}
						}
					}
				}
			}
		}
		if(movimentodecomer.size() != 0) {
			random_shuffle(movimentodecomer.begin(), movimentodecomer.end());
			pair<pair<int,int>, pair<int, int>> escolhido = *movimentodecomer.rbegin();
			colunainicial = escolhido.first.first;
			filainicial = escolhido.first.second;
			colunafinal = escolhido.second.first;
			filafinal = escolhido.second.second;
			lance.push_back('a' + colunainicial);
			lance.push_back('1' + filainicial);
			lance.push_back('a' + colunafinal);
			lance.push_back('1' + filafinal);
			cout << "Jogada do computador: " << lance << "\n";
			return lance;	
		}
		else if(movimentorainha.size() !=0) {
			random_shuffle(movimentorainha.begin(), movimentorainha.end());
			pair<pair<int,int>, pair<int, int>> escolhido = *movimentorainha.rbegin();
			colunainicial = escolhido.first.first;
			filainicial = escolhido.first.second;
			colunafinal = escolhido.second.first;
			filafinal = escolhido.second.second;
			lance.push_back('a' + colunainicial);
			lance.push_back('1' + filainicial);
			lance.push_back('a' + colunafinal);
			lance.push_back('1' + filafinal);
			cout << "Jogada do computador: " << lance << "\n";
			return lance;			
		}
		else if(movimentosemcomer.size() != 0){
			random_shuffle(movimentosemcomer.begin(), movimentosemcomer.end());
			pair<pair<int,int>, pair<int, int>> escolhido = *movimentosemcomer.rbegin();
			colunainicial = escolhido.first.first;
			filainicial = escolhido.first.second;
			colunafinal = escolhido.second.first;
			filafinal = escolhido.second.second;
			lance.push_back('a' + colunainicial);
			lance.push_back('1' + filainicial);
			lance.push_back('a' + colunafinal);
			lance.push_back('1' + filafinal);
			cout << "Jogada do computador: " << lance << "\n";
			return lance;
		}
		else {
			return "acabou";
		}
	}
	
	void jogada_invalida() {
		cout << "Jogada Invalida! Tente novamente: ";
		string outro_lance;
		cin >> outro_lance;
		movimento(outro_lance);
	}
	void movimento(string lance) {
		if(lance.length() != 4) {
			jogada_invalida();
			return;
		}
		if(lance[0] > 'h' or lance[0] < 'a' or lance[1] > '8' or lance[1] < '1' or lance[2] > 'h' or lance[2] < 'a' or lance[3] > '8' or lance[3] < '1') {
			jogada_invalida();
			return;
		}
		int colunainicial = lance[0] - (int)'a';
		int filainicial = lance[1] - (int)'1';
		int colunafinal = lance[2] - (int)'a';
		int filafinal = lance[3] - (int)'1';
		
		if(tabuleiro[colunainicial][filainicial]->getdono() != vez) {
			jogada_invalida();
		}
		else {
			if(!tabuleiro[colunainicial][filainicial]->jogada(tabuleiro, colunafinal, filafinal,0)) {
				jogada_invalida();
			}
		}
		if(tabuleiro[0][0]->pecascomputador == 0 or tabuleiro[0][0]->pecasjogador == 0)
			gameover = true;
	}
	
	void partida() {
		string lance;
		while(true) {
			if(vez == jogador) {
				if(jogador_preso()) {
					cout << "Nao ha mais jogadas possiveis para o jogador!\n";
					gameover = true;
					vez = computador;
				}
				else {
					cout << "Digite sua jogada: ";
					cin >> lance;
					movimento(lance);
					imprimir();
				}
				if(FimdoJogo())
					break;
				vez = computador;
			}
			else {
				lance = jogada_computador();
				if(lance == "acabou") {
					vez = jogador;
					gameover = true;
					cout << "Nao ha mais jogadas possiveis para o computador!\n";
				}
				else {
					movimento(lance);
					imprimir();
				}
				if(FimdoJogo())
					break;
				vez = jogador;	
			}
		}
	}
	
	void imprimir() {
		cout << "  a b c d e f g h " << endl;
		for(int i = 7; i >=0; i--) {
			for(int j = 0; j < 8; j++) {
				if ( j == 0 ) {
					changeColor(7);
					cout << i + 1 << " ";
				}
				if ( tabuleiro[ j ][ i ]->gettipo() == vazio)  
				{
					changeColor(7);
					cout << "-";
				}
				else {
					if ( tabuleiro[ j ][ i ]->getdono() == jogador) {
						changeColor(10); //jogador eh o verde
						if(tabuleiro[j][i]->gettipo() == comum)
							cout << "o";
						if(tabuleiro[j][i]->gettipo() == rainha)
							cout << "R";
					}
					else {
						changeColor(12); // computador eh o vermelho
						if(tabuleiro[j][i]->gettipo() == comum)
							cout << "o";
						if(tabuleiro[j][i]->gettipo() == rainha)
							cout << "R";
					}
				}
				changeColor(7); 
				cout << "|";
				if ( j == 7 ) cout << " " << i + 1;
				
			}
			changeColor(7); 
			cout << "" << endl;
		}
		changeColor(7); 
		cout << "  a b c d e f g h \n" << endl;
		cout << "pecas comidas pelo jogador: " << (12 - tabuleiro[0][0]->pecascomputador) << "\n";
		cout << "pecas comidas pelo computador: " << (12 - tabuleiro[0][0]->pecasjogador) << "\n";
		cout << "\n";
	}
	void iniciar_partida() {
		cout << "Bem-vindo ao Jogo de Damas! O jogador controla as pecas verdes e o computador, as vermelhas. Sera que voce conseguira vencer o computador?!\n";
		cout << "Para inserir a jogada, digite a posicao da peca a ser movida e a posicao de destino, ex: a3b4\n";
		cout << "Bom jogo!\n";
		imprimir();
		partida();
		
	}
		
};

int main() {
	srand (time (0));
	Dama t;
	t.iniciar_partida();
	return 0;
}