#include <iostream>

using namespace std;

int mark(char position[8][8], int i, int j);
int counter(char position[8][8], int j);

void test(char position[8][8]){
    position[0][0] = 'x';
}

int main(){
    char position[8][8];

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> position[i][j];
        }
    }

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << position[i][j] << " ";
        }
        cout << "\n";
    }
    

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << position[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int mark(char position[8][8], int i, int j){
    for (int k = 1; k+j<8; k++){
        if (i+k < 8 ){
            position[i+k][j+k] = '*';
        }
        if (i-k >= 0){
            position[i-k][j+k] = '*';
        }
        position[i][j+k] = '*';
    }
    return counter(position, j+1);
}

int counter(char position[8][8], int j){
    int count = 0;

    if (j == 7){
        for (int i = 0; i < 8; i++){
            if (position[i][j] == '.'){
                count++;
            }
        }
    }
    else {
        for (int i = 0; i < 8; i++){
            if (position[i][j] == '.'){
                count += mark(position, i, j);
            }
        }
    }

    return count;
}