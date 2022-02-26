#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    bool ok = false;
    for(int i = 0; i <= x; i++){
        if(i*2 + (x - i)*4 == y) ok = true; 
    }
    if(ok) printf("Yes\n");
    else printf("No\n");
    return 0;
}