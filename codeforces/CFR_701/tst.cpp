#include <bits/stdc++.h>

const double PI = acos(-1.);

const int N = 1000;

int vetor[N];
//vetor[i][j]

int main(){
    printf("%.10lf",PI);
    int n;
    scanf("%d",&n);
    //n <= 1000
    for(int i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
    // vetor : 1 4 3 2 0 0 0  0 0 0 0 0 0 0 0 0 0 
    //         0 1 2 3
    for(int i=n-1;i>=0;i--){
        printf("%d ",vetor[i]);
    }
    return 0;
}

//segmentation fault