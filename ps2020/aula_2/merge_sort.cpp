#include <bits/stdc++.h>

using namespace std;


int arr[] = {2, 8, 6, 10, 4, 3, 7, 5, 9, 11}; 

void merge(int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i] = arr[l+i];
    for(int i=0;i<n2;i++) R[i] = arr[m+1+i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]) arr[k] = L[i], i++;
        else arr[k] = R[j], j++;
        k++;
    }
    while(i<n1) arr[k] = L[i], i++, k++;
    while(j<n2) arr[k] = R[j], j++, k++;
}

void mergesort(int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergesort(l,m);
        mergesort(m+1,r);
        merge(l,m,r);
    }
}
void print(int size) { 
    for (int i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
int main() { 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Array original \n"); 
    print(arr_size); 
  
    mergesort(0, arr_size - 1); 
  
    printf("\nArray ordenado \n"); 
    print(arr_size); 
    return 0; 
} 