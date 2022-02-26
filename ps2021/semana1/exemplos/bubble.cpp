#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int v[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2 , 1};

int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++){
            if(v[j+1] < v[j]){
                swap(v[j], v[j+1]);
            }
        }
    }
    for(int i = 0; i < N; i++) printf("%d ", v[i]);
}