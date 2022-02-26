#include <bits/stdc++.h>

using namespace std;

multiset<int> s[2];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        s[x%2].insert(x);
    }
    for(auto it = s[0].begin();it != s[0].end(); it++){
        printf("%d\n", *it);
    }
    for(auto it = s[1].rbegin(); it != s[1].rend(); it++){
        printf("%d\n", *it);
    }
    return 0;
} 