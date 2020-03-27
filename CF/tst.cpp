#include<bits/stdc++.h>

using namespace std;

int main(){
    int T, aux=0, a, aux2=0;
    cin >> T;
    vector<int> v;
    v.resize(T+1);
    v[0]=0;
    int i=0;
    while(T){
        T--;
        cin >> a;
        if(a==aux)v[i]++;
        else{
            aux=a;
            i++;
            v[i]=1;
        }

    }
    if(i==0){cout << v[0]; return 0;}
    int cont=0;
    aux=0;
    for(int j=1; j<i+1; j=j+2){
        cont+=v[j];
        if(aux<v[j-1])aux=v[j-1];
    }
    if(i%2==0){if(aux<v[i])aux=v[i];}
    //cont+=aux;
    for(int h=0; h<i-1; h=h+2){
        aux2=v[h];
        for(int k=h+1; k< i+1; k=k+2){
            aux2+=-v[k]+v[k+1];
            if(aux<aux2){aux=aux2;}
        }
    }
    cout << cont+aux;
    return 0;

}