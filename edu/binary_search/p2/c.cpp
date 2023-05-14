#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, x, y; 
    scanf("%lld%lld%lld", &n, &x, &y);
    n--;
    long long l = 0, r = n*min(x,y);
    while(l < r){
        long long m = (l+r)/2;
        if(m/x + m/y < n) l = m + 1;
        else r = m;
    }
    printf("%lld\n", l + min(x,y));
    return 0;
}