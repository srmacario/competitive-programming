#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, y; 
    scanf("%d%d%d", &n, &x, &y);
    int l = 0, r = n/x;
    while(l < r){
        int m = (l+r)/2;
        if(m/x + m/y < n) l = m + 1;
        r = m;
    }
    printf("%d\n", l + x);
    return 0;
}