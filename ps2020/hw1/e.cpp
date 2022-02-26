#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    bool ok = false;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d", &x, &y);
        if(x!=y) ok = true;
    }
    printf("%s\n", ok ? "Happy Alex" : "Poor Alex");
}