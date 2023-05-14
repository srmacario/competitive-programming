#include <stdio.h>

int main(){
    int x = 2;
    int y = 2;
    int z = 2;
    x ^= y | z;
    printf("%d", x);
    return 0;
}